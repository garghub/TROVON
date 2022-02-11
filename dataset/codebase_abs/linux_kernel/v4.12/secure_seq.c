static T_1 void F_1 ( void )
{
F_2 ( & V_1 , sizeof( V_1 ) ) ;
}
static T_1 void F_3 ( void )
{
F_2 ( & V_2 , sizeof( V_2 ) ) ;
}
static T_2 F_4 ( T_2 V_3 )
{
return V_3 + ( F_5 () >> 6 ) ;
}
T_2 F_6 ( const T_3 * V_4 , const T_3 * V_5 )
{
const struct {
struct V_6 V_4 ;
struct V_6 V_5 ;
} V_7 ( V_8 ) V_9 = {
. V_4 = * (struct V_6 * ) V_4 ,
. V_5 = * (struct V_6 * ) V_5 ,
} ;
if ( V_10 != 1 )
return 0 ;
F_3 () ;
return F_7 ( & V_9 , F_8 ( F_9 ( V_9 ) , V_5 ) ,
& V_2 ) ;
}
T_2 F_10 ( const T_3 * V_4 , const T_3 * V_5 ,
T_4 V_11 , T_4 V_12 )
{
const struct {
struct V_6 V_4 ;
struct V_6 V_5 ;
T_4 V_11 ;
T_4 V_12 ;
} V_7 ( V_8 ) V_9 = {
. V_4 = * (struct V_6 * ) V_4 ,
. V_5 = * (struct V_6 * ) V_5 ,
. V_11 = V_11 ,
. V_12 = V_12
} ;
T_2 V_13 ;
F_1 () ;
V_13 = F_7 ( & V_9 , F_8 ( F_9 ( V_9 ) , V_12 ) ,
& V_1 ) ;
return F_4 ( V_13 ) ;
}
T_2 F_11 ( const T_3 * V_4 , const T_3 * V_5 ,
T_4 V_12 )
{
const struct {
struct V_6 V_4 ;
struct V_6 V_5 ;
T_4 V_12 ;
} V_7 ( V_8 ) V_9 = {
. V_4 = * (struct V_6 * ) V_4 ,
. V_5 = * (struct V_6 * ) V_5 ,
. V_12 = V_12
} ;
F_1 () ;
return F_7 ( & V_9 , F_8 ( F_9 ( V_9 ) , V_12 ) ,
& V_1 ) ;
}
T_2 F_12 ( T_3 V_4 , T_3 V_5 )
{
if ( V_10 != 1 )
return 0 ;
F_3 () ;
return F_13 ( ( V_14 T_2 ) V_4 , ( V_14 T_2 ) V_5 ,
& V_2 ) ;
}
T_2 F_14 ( T_3 V_4 , T_3 V_5 ,
T_4 V_11 , T_4 V_12 )
{
T_2 V_13 ;
F_1 () ;
V_13 = F_15 ( ( V_14 T_2 ) V_4 , ( V_14 T_2 ) V_5 ,
( V_14 T_2 ) V_11 << 16 | ( V_14 T_2 ) V_12 ,
& V_1 ) ;
return F_4 ( V_13 ) ;
}
T_2 F_16 ( T_3 V_4 , T_3 V_5 , T_4 V_12 )
{
F_1 () ;
return F_15 ( ( V_14 T_2 ) V_4 , ( V_14 T_2 ) V_5 ,
( V_14 V_15 ) V_12 , & V_1 ) ;
}
T_5 F_17 ( T_3 V_4 , T_3 V_5 ,
T_4 V_11 , T_4 V_12 )
{
T_5 V_3 ;
F_1 () ;
V_3 = F_15 ( ( V_14 T_2 ) V_4 , ( V_14 T_2 ) V_5 ,
( V_14 T_2 ) V_11 << 16 | ( V_14 T_2 ) V_12 ,
& V_1 ) ;
V_3 += F_5 () ;
V_3 &= ( 1ull << 48 ) - 1 ;
return V_3 ;
}
T_5 F_18 ( T_3 * V_4 , T_3 * V_5 ,
T_4 V_11 , T_4 V_12 )
{
const struct {
struct V_6 V_4 ;
struct V_6 V_5 ;
T_4 V_11 ;
T_4 V_12 ;
} V_7 ( V_8 ) V_9 = {
. V_4 = * (struct V_6 * ) V_4 ,
. V_5 = * (struct V_6 * ) V_5 ,
. V_11 = V_11 ,
. V_12 = V_12
} ;
T_5 V_3 ;
F_1 () ;
V_3 = F_7 ( & V_9 , F_8 ( F_9 ( V_9 ) , V_12 ) ,
& V_1 ) ;
V_3 += F_5 () ;
V_3 &= ( 1ull << 48 ) - 1 ;
return V_3 ;
}
