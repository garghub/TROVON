static void F_1 ( T_1 V_1 , T_2 V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = ( ( F_2 ( V_1 >> 24 ) * 100 ) +
F_2 ( ( V_1 >> 16 ) & 0xff ) ) - 1900 ;
V_4 -> V_6 = F_2 ( ( V_1 >> 8 ) & 0xff ) - 1 ;
V_4 -> V_7 = F_2 ( V_1 & 0xff ) ;
V_4 -> V_8 = F_2 ( ( V_2 >> 56 ) & 0xff ) ;
V_4 -> V_9 = F_2 ( ( V_2 >> 48 ) & 0xff ) ;
V_4 -> V_10 = F_2 ( ( V_2 >> 40 ) & 0xff ) ;
F_3 ( V_4 ) ;
}
unsigned long T_3 F_4 ( void )
{
struct V_3 V_4 ;
T_1 V_1 ;
T_2 V_2 ;
T_4 V_11 ;
T_5 V_12 ;
long V_13 = V_14 ;
if ( ! F_5 ( V_15 ) )
return 0 ;
while ( V_13 == V_14 || V_13 == V_16 ) {
V_13 = F_6 ( & V_11 , & V_12 ) ;
if ( V_13 == V_16 )
F_7 ( NULL ) ;
else
F_8 ( 10 ) ;
}
if ( V_13 != V_17 )
return 0 ;
V_1 = F_9 ( V_11 ) ;
V_2 = F_10 ( V_12 ) ;
F_1 ( V_1 , V_2 , & V_4 ) ;
return mktime ( V_4 . V_5 + 1900 , V_4 . V_6 + 1 , V_4 . V_7 ,
V_4 . V_8 , V_4 . V_9 , V_4 . V_10 ) ;
}
static T_3 int F_11 ( void )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
V_21 = F_12 ( L_1 ) ;
if ( V_21 ) {
V_19 = F_13 ( V_21 , L_2 , NULL ) ;
F_14 ( V_21 ) ;
} else {
if ( F_5 ( V_15 ) ||
F_5 ( V_22 ) )
V_19 = F_15 ( L_2 , - 1 ,
NULL , 0 ) ;
else
return - V_23 ;
}
return F_16 ( V_19 ) ;
}
