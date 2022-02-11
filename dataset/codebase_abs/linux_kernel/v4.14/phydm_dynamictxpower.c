void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = V_5 ;
V_3 -> V_7 =
F_2 ( V_3 , 0xC24 , V_8 ) ;
}
void F_3 ( void * V_1 ) {}
void F_4 ( void * V_1 ) {}
void F_5 ( void * V_1 , T_1 V_9 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_1 V_10 ;
T_2 V_11 [ 6 ] = { 0xc90 , 0xc91 , 0xc92 , 0xc98 , 0xc99 , 0xc9a } ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
F_6 ( V_3 , V_11 [ V_10 ] , V_9 ) ;
}
static void F_7 ( void * V_1 ) {}
void F_8 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! ( V_3 -> V_12 & V_13 ) )
return;
switch ( V_3 -> V_14 ) {
case V_15 :
F_9 ( V_3 ) ;
break;
case V_16 :
F_7 ( V_3 ) ;
break;
case V_17 :
F_10 ( V_3 ) ;
break;
default:
break;
}
}
void F_9 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! ( V_3 -> V_12 & V_13 ) )
return;
}
void F_10 ( void * V_1
)
{
}
void F_11 ( void * V_1 , T_1 * V_18 , T_1 V_19 ) {}
