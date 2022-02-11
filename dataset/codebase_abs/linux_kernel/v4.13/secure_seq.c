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
T_2 F_6 ( const struct V_4 * V_4 ,
const T_3 * V_5 , const T_3 * V_6 )
{
const struct {
struct V_7 V_5 ;
struct V_7 V_6 ;
} V_8 ( V_9 ) V_10 = {
. V_5 = * (struct V_7 * ) V_5 ,
. V_6 = * (struct V_7 * ) V_6 ,
} ;
if ( V_4 -> V_11 . V_12 != 1 )
return 0 ;
F_3 () ;
return F_7 ( & V_10 , F_8 ( F_9 ( V_10 ) , V_6 ) ,
& V_2 ) ;
}
T_2 F_10 ( const T_3 * V_5 , const T_3 * V_6 ,
T_4 V_13 , T_4 V_14 )
{
const struct {
struct V_7 V_5 ;
struct V_7 V_6 ;
T_4 V_13 ;
T_4 V_14 ;
} V_8 ( V_9 ) V_10 = {
. V_5 = * (struct V_7 * ) V_5 ,
. V_6 = * (struct V_7 * ) V_6 ,
. V_13 = V_13 ,
. V_14 = V_14
} ;
T_2 V_15 ;
F_1 () ;
V_15 = F_7 ( & V_10 , F_8 ( F_9 ( V_10 ) , V_14 ) ,
& V_1 ) ;
return F_4 ( V_15 ) ;
}
T_2 F_11 ( const T_3 * V_5 , const T_3 * V_6 ,
T_4 V_14 )
{
const struct {
struct V_7 V_5 ;
struct V_7 V_6 ;
T_4 V_14 ;
} V_8 ( V_9 ) V_10 = {
. V_5 = * (struct V_7 * ) V_5 ,
. V_6 = * (struct V_7 * ) V_6 ,
. V_14 = V_14
} ;
F_1 () ;
return F_7 ( & V_10 , F_8 ( F_9 ( V_10 ) , V_14 ) ,
& V_1 ) ;
}
T_2 F_12 ( const struct V_4 * V_4 , T_3 V_5 , T_3 V_6 )
{
if ( V_4 -> V_11 . V_12 != 1 )
return 0 ;
F_3 () ;
return F_13 ( ( V_16 T_2 ) V_5 , ( V_16 T_2 ) V_6 ,
& V_2 ) ;
}
T_2 F_14 ( T_3 V_5 , T_3 V_6 ,
T_4 V_13 , T_4 V_14 )
{
T_2 V_15 ;
F_1 () ;
V_15 = F_15 ( ( V_16 T_2 ) V_5 , ( V_16 T_2 ) V_6 ,
( V_16 T_2 ) V_13 << 16 | ( V_16 T_2 ) V_14 ,
& V_1 ) ;
return F_4 ( V_15 ) ;
}
T_2 F_16 ( T_3 V_5 , T_3 V_6 , T_4 V_14 )
{
F_1 () ;
return F_15 ( ( V_16 T_2 ) V_5 , ( V_16 T_2 ) V_6 ,
( V_16 V_17 ) V_14 , & V_1 ) ;
}
T_5 F_17 ( T_3 V_5 , T_3 V_6 ,
T_4 V_13 , T_4 V_14 )
{
T_5 V_3 ;
F_1 () ;
V_3 = F_15 ( ( V_16 T_2 ) V_5 , ( V_16 T_2 ) V_6 ,
( V_16 T_2 ) V_13 << 16 | ( V_16 T_2 ) V_14 ,
& V_1 ) ;
V_3 += F_5 () ;
V_3 &= ( 1ull << 48 ) - 1 ;
return V_3 ;
}
T_5 F_18 ( T_3 * V_5 , T_3 * V_6 ,
T_4 V_13 , T_4 V_14 )
{
const struct {
struct V_7 V_5 ;
struct V_7 V_6 ;
T_4 V_13 ;
T_4 V_14 ;
} V_8 ( V_9 ) V_10 = {
. V_5 = * (struct V_7 * ) V_5 ,
. V_6 = * (struct V_7 * ) V_6 ,
. V_13 = V_13 ,
. V_14 = V_14
} ;
T_5 V_3 ;
F_1 () ;
V_3 = F_7 ( & V_10 , F_8 ( F_9 ( V_10 ) , V_14 ) ,
& V_1 ) ;
V_3 += F_5 () ;
V_3 &= ( 1ull << 48 ) - 1 ;
return V_3 ;
}
