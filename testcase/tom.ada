program TestProgram
    -- Declaration
    declare
        Gint := -10;
        Gint1 := -10;
        Gint2 : integer;
        Gint3 : integer := 20;
        Gint4;
        Gbool2 : boolean := false;
        GCint : constant := -30;
        GCbool : constant := false;
        GCstring : constant : string := "Constant String 001";

        Gint6 : integer;
        Gint44 : integer := 20;
        Gint89;

        Gint21 : integer;
        Gint33 : integer := 20;
        Gint43;

    -- Procudure
    procedure fib(a: integer) return integer
        begin
            if (a <= 2) then
                return 1;
            end if;

            return fib(a - 1) + fib(a - 2);
        end;
    end fib;

    procedure add (a: integer; b: integer) return integer
        begin
            return a + b;
        end;
    end add;

    procedure forLoop
        declare
            n: integer;
        begin
            for (n in 1.. 10) loop
                println n;
            end loop;
        end;
    end forLoop;

    procedure boolProcedure return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure;

        procedure boolProcedure1 return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure1;

        procedure boolProcedure2 return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure2;

    procedure boolProcedure3 return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure3;

    procedure boolProcedure4 return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure4;

    procedure boolProcedure5 return boolean
        declare
            a := 10;
            b := 20;
        begin
            return a < b;
        end;
    end boolProcedure5;

    -- main block
    begin
        println "== print string";
        println "raw string";
        println "== print constant string";
        println GCstring;
        
        println "== procedure recursion test";
        println "== fib(20) should be 6765";
        Gint4 := fib(20);
        println Gint4;

        println "== for loop test";
        forLoop;

        println "== if statement test";
        print "Gint1: ";
        println Gint1;
        print "Gint2: ";
        println Gint2;
        Gint4 := add(Gint1, Gint2);

        println "Gint4 := add(Gint1, Gint2);";
        print "Gint4: ";
        println Gint4;


        if (Gint4 = 10) then
            begin
                println "(Gint4 = 10) executed!";
            end;
        else
            println "(Gint4 /= 10) executed!";
        end if;
        if (Gint4 = 15) then
            begin
                println "(Gint4 = 15) executed!";
            end;
        end if;
        
        if ( not true) then
            begin
                println " normal Gint ";
                println Gint;
            end;
        else
            begin
                println " neg Gint ";
                println -Gint;
            end;
        end if;
        println Gint1; 
        println boolProcedure;
    end;
end TestProgram