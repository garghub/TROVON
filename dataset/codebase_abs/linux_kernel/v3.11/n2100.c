static void T_1 F_1 ( void )
{
F_2 ( 198000000 ) ;
}
void T_1 F_3 ( void )
{
F_4 () ;
F_5 ( V_1 , F_6 ( V_1 ) ) ;
}
static int T_1
F_7 ( const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 ;
if ( F_8 ( V_3 -> V_7 ) == 1 ) {
V_6 = V_8 ;
} else if ( F_8 ( V_3 -> V_7 ) == 2 ) {
V_6 = V_9 ;
} else if ( F_8 ( V_3 -> V_7 ) == 3 ) {
V_6 = V_10 ;
} else if ( F_8 ( V_3 -> V_7 ) == 4 && V_5 == 1 ) {
V_6 = V_11 ;
} else if ( F_8 ( V_3 -> V_7 ) == 4 && V_5 == 2 ) {
V_6 = V_8 ;
} else if ( F_8 ( V_3 -> V_7 ) == 4 && V_5 == 3 ) {
V_6 = V_10 ;
} else if ( F_8 ( V_3 -> V_7 ) == 5 ) {
V_6 = V_9 ;
} else {
F_9 ( V_12 L_1
L_2 , V_3 -> V_13 -> V_14 ,
F_8 ( V_3 -> V_7 ) , F_10 ( V_3 -> V_7 ) ) ;
V_6 = - 1 ;
}
return V_6 ;
}
static void F_11 ( struct V_2 * V_3 )
{
if ( V_3 -> V_13 -> V_14 == 0 &&
( V_3 -> V_7 == F_12 ( 1 , 0 ) ||
V_3 -> V_7 == F_12 ( 2 , 0 ) ) )
V_3 -> V_15 = 1 ;
}
static int T_1 F_13 ( void )
{
if ( F_14 () )
F_15 ( & V_16 ) ;
return 0 ;
}
static void F_16 ( void )
{
F_17 () ;
* V_17 = 0xc0 ;
* V_18 = 0xe9 ;
F_18 ( 1 ) ;
* V_17 = 0x08 ;
* V_18 = 0xe8 ;
F_18 ( 1 ) ;
* V_17 = 0x01 ;
* V_18 = 0xea ;
while ( 1 )
;
}
static void F_19 ( enum V_19 V_20 , const char * V_21 )
{
F_20 ( V_22 , V_23 ) ;
F_21 ( V_22 , V_24 ) ;
while ( 1 )
;
}
static void F_22 ( unsigned long V_25 )
{
if ( F_23 ( V_26 ) == 0 ) {
F_24 () ;
return;
}
V_27 . V_28 = V_29 + ( V_30 / 10 ) ;
F_25 ( & V_27 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( & V_31 ) ;
F_27 ( & V_32 ) ;
F_27 ( & V_33 ) ;
F_27 ( & V_34 ) ;
F_27 ( & V_35 ) ;
F_28 ( 0 , V_36 ,
F_6 ( V_36 ) ) ;
V_37 = F_16 ;
F_29 ( & V_27 ) ;
V_27 . V_38 = F_22 ;
V_27 . V_28 = V_29 + ( V_30 / 10 ) ;
F_25 ( & V_27 ) ;
}
