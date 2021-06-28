program myTestCase
-- global variable
    declare
        -- should not output anything
        trash := 1.0;


        -- -----------------------------
        
        a : constant := 1 + 2 + 4;
      
        one := 1;
        three := 3;
          bbbb :constant := a + 5;
        hanoiCount := 0;
       -- b := 10;
        c : integer;
        uglyStringConstant :constant := "u""g""l""y""c";
        uglyStringVariable :=  "u""g""l""y""v";
        tr := true;
        trueTestVariable := tr;
        falseTestVariable := false;
    procedure factorialIterative (n: integer) return integer
        declare 
            k := 1;
            i : integer;
        begin
            println "Enter factorialIterative ----------------------------------";
            print("n: ");
            println n;
            if(n = 0) then
               return 1;
            else 
            
               begin
               println n = 0;
                for (i in n .. 1) loop
                    begin
                    print i;
                    k := k * i;
                    end;
                end loop;
                    return k ;
                end;
            end if;
           
        end;
    end     factorialIterative;
    procedure factorialRecusive (n: integer) return integer
        begin
            println "Enter factorialRecusive ----------------------------------";
            if (n = 0) then
                return 1;
            else
                return n * factorialRecusive(n-1);
            end if;
        end;
    end factorialRecusive;
    
    procedure hanoi (n: integer; a:integer; b: integer; c:integer) 
        begin
            println "Enter hanoi ----------------------------------";
           if (n = 1) then 
            begin
                print "let ";
                print n;
                hanoiCount := hanoiCount + 1;
                print " move from ";
                print a;
                print " to ";
                println c;
            end;
            else
             begin
                hanoi(n-1, a, c, b);
                print "let ";
                print n;
                hanoiCount := hanoiCount + 1;
                print " move from ";
                print a;
                print " to ";
                println c;
                hanoi(n-1, b, a, c);
             end;
            end if;
        end;
    end hanoi;
    procedure multiLoop
        declare
            i:=0;
            j:=0;
            k:=0;
        begin
            println "Enter multiLoop ----------------------------------";
            for (i in 0..3) loop
                begin
                    for (j in one..three)loop
                        begin
                            for(k in three.. one)loop
                            begin
                                print i;
                                print j;
                                println k;
                            end;
                            end loop;
                        end;
                    end loop;
                end;
            end loop;
        end;
    end multiLoop;
    procedure multiParameterAndBool (n: integer; t: boolean; f: boolean) return boolean
        begin
            println "Enter multiParameterAndBool ----------------------------------";
            if t then
                begin
                    print "ture read: ";
                    println (t);
                end;
            end if;
            if not f then
                begin
                    print "false read: ";
                    println f;
                end;
            end if;
        return false;
        end; 
    end multiParameterAndBool;
    procedure forWhilefor (n: integer) 
        declare
            i := 0;
            count := 0;
        begin
            println "Enter forWhilefor ----------------------------------";
            for (i in -2..3) loop
                declare
                    k := 0;
                begin
                    k := i;
                    while (k % 2) = 0 loop
                        declare 
                            p := 0;
                        begin
                            print "current k :";
                            println k;
                            for (p in 3 .. 0) loop
                                println p;
                            end loop;
                           k := k + 1; 
                        end;
                    end loop;
                end;
            end loop;                                
        end; 
    end forWhilefor;

    procedure whileForWhile (t:boolean) 
        declare
            i := 0;
            count := 0;
        begin
            println "Enter whileForWhile ----------------------------------";
            if t then
            begin
                while (i < 3) loop
                    begin                       
                        for (count in 0 .. 2) loop
                            declare
                                count2 := -1;
                            begin
                                while (count2 > -5) loop
                                    begin
                                        println count2;
                                        count2 := count2 - 1;
                                        
                                    end;
                                end loop;
                                println "--a------------";
                            end;
                        end loop;
                        i := i + 1;
                    end;
                end loop;    
            end;
        end if;            
        end; 
    end whileForWhile;
    procedure calculate 
        declare
            i := 0;
            boolGlobal := NOT true OR false OR 12-6 >= 0 AND NOT trueTestVariable ; -- this shit equals true;
        begin
            println "Enter calculate----------------------------------";
            i := 12/ (2 % (3 % 2) + 1) + 4 * 2 + 12 / 3 - -15 * -4 ; -- this shit equals -36
            println i;
            println boolGlobal;
        end; 
    end calculate;
    procedure ifForIfElseif 
        declare
            bb := a + 15;
            a := false;
            
        begin
            println "Enter ifForIfElseif ----------------------------------";
            print "bbbbbb";
            print bb;
            if  true then
                declare
                    first := -32;
                begin 
                    println "aa";
                    println first;
                    for (first in -2 .. 2) loop
                        declare
                            second := 255;
                            third := true;
                        begin
                            print "first: ";
                            println first;
                            if second /= 255 AND third then
                                begin

                                first :=2;
                               
                                end;
                            else 
                             begin
                                print 0;
                                second := 256;
                             end;
                            end if;
                        end;
                    end loop;
                end;
            end if;
            
        end; 
    end ifForIfElseif;
    begin
        println "Enter main block ----------------------------------";
        print "Iterative: ";
        println factorialIterative(5);
        print "Recusive: ";
        println factorialRecusive(6);
        
        hanoi(3, 1,2,3);
        print "hanoiCount: ";
        println hanoiCount;
        trueTestVariable := multiParameterAndBool(0, trueTestVariable, falseTestVariable);
        if (multiParameterAndBool(0, trueTestVariable, falseTestVariable)) then
            println "success";
        else 
            println "fail";
        end if;
        if NOT true OR false OR 12-6 >= 0 AND  trueTestVariable then
            println "shit";
        else
            println "no";
        end if;
        forWhilefor(10);
        whileForWhile(true);
        println uglyStringConstant;
        println uglyStringVariable; --  should not print anyth
        println "calculate :";
        calculate;
        ifForIfElseif;
        print "bbbb";
        print multiParameterAndBool(0, trueTestVariable, falseTestVariable);
        multiLoop;
    end; 
end myTestCase
