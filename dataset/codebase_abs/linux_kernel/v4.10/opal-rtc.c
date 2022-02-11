static void F_1 ( T_1 V_1 , T_2 V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = ( ( F_2 ( V_1 >> 24 ) * 100 ) +
F_2 ( ( V_1 >> 16 ) & 0xff ) ) - 1900 ;
V_4 -> V_6 = F_2 ( ( V_1 >> 8 ) & 0xff ) - 1 ;
V_4 -> V_7 = F_2 ( V_1 & 0xff ) ;
V_4 -> V_8 = F_2 ( ( V_2 >> 56 ) & 0xff ) ;
V_4 -> V_9 = F_2 ( ( V_2 >> 48 ) & 0xff ) ;
V_4 -> V_10 = F_2 ( ( V_2 >> 40 ) & 0xff ) ;
V_4 -> V_11 = - 1 ;
}
unsigned long T_3 F_3 ( void )
{
struct V_3 V_4 ;
T_1 V_1 ;
T_2 V_2 ;
T_4 V_12 ;
T_5 V_13 ;
long V_14 = V_15 ;
if ( ! F_4 ( V_16 ) )
return 0 ;
while ( V_14 == V_15 || V_14 == V_17 ) {
V_14 = F_5 ( & V_12 , & V_13 ) ;
if ( V_14 == V_17 )
F_6 ( NULL ) ;
else if ( V_14 == V_15 )
F_7 ( 10 ) ;
}
if ( V_14 != V_18 )
return 0 ;
V_1 = F_8 ( V_12 ) ;
V_2 = F_9 ( V_13 ) ;
F_1 ( V_1 , V_2 , & V_4 ) ;
return mktime ( V_4 . V_5 + 1900 , V_4 . V_6 + 1 , V_4 . V_7 ,
V_4 . V_8 , V_4 . V_9 , V_4 . V_10 ) ;
}
static T_3 int F_10 ( void )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_22 = F_11 ( L_1 ) ;
if ( V_22 ) {
V_20 = F_12 ( V_22 , L_2 , NULL ) ;
F_13 ( V_22 ) ;
} else {
if ( F_4 ( V_16 ) ||
F_4 ( V_23 ) )
V_20 = F_14 ( L_2 , - 1 ,
NULL , 0 ) ;
else
return - V_24 ;
}
return F_15 ( V_20 ) ;
}
