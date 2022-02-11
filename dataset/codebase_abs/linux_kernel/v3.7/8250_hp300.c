int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
if ( V_4 < 0 || V_4 > V_5 )
return 0 ;
if ( F_2 ( V_4 ) )
return 0 ;
V_1 = V_4 ;
V_3 . V_6 = V_7 ;
V_3 . V_8 = V_9 | V_10 | V_11 ;
V_3 . type = V_12 ;
if ( V_1 == 256 ) {
#ifdef F_3
F_4 ( V_13 L_1 ) ;
V_3 . V_14 = V_15 * 16 ;
V_3 . V_16 = ( V_17 + F_5 ( 1 ) ) ;
V_3 . V_18 = ( char * ) ( V_3 . V_16 + V_19 ) ;
V_3 . V_20 = 2 ;
F_6 ( L_2 , V_3 . line , L_3 ) ;
#else
F_4 ( V_21 L_4 ) ;
return 0 ;
#endif
} else {
#ifdef F_7
unsigned long V_22 = F_8 ( V_1 ) ;
if ( ! V_22 )
return 0 ;
F_4 ( V_13 L_5 , V_1 ) ;
V_3 . V_14 = V_23 * 16 ;
V_3 . V_16 = ( V_22 + V_24 ) ;
V_3 . V_18 = ( char * ) ( V_3 . V_16 + V_19 ) ;
V_3 . V_20 = 1 ;
V_3 . V_25 = F_9 ( V_22 + V_19 ) ;
F_10 ( V_22 + V_19 + V_26 , V_27 ) ;
if ( F_11 ( V_22 + V_19 ) & 0x80 )
F_6 ( L_2 , V_3 . line , L_3 ) ;
#else
F_4 ( V_21 L_6 ) ;
return 0 ;
#endif
}
if ( F_12 ( & V_3 ) < 0 )
F_4 ( V_21 L_7 ) ;
return 0 ;
}
static int T_2 F_13 ( struct V_28 * V_29 ,
const struct V_30 * V_31 )
{
struct V_32 V_33 ;
int line ;
#ifdef F_14
if ( V_4 == V_29 -> V_1 ) {
return 0 ;
}
#endif
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_3 . V_6 = V_7 ;
V_33 . V_3 . V_8 = V_9 | V_10 | V_11 ;
V_33 . V_3 . V_25 = V_29 -> V_34 ;
V_33 . V_3 . V_14 = V_23 * 16 ;
V_33 . V_3 . V_16 = ( V_29 -> V_35 . V_36 + V_24 ) ;
V_33 . V_3 . V_18 = ( char * ) ( V_33 . V_3 . V_16 + V_19 ) ;
V_33 . V_3 . V_20 = 1 ;
V_33 . V_3 . V_37 = & V_29 -> V_37 ;
line = F_15 ( & V_33 ) ;
if ( line < 0 ) {
F_4 ( V_38 L_8
L_9 , V_29 -> V_1 , V_33 . V_3 . V_25 ) ;
return - V_39 ;
}
F_10 ( V_29 -> V_35 . V_36 + V_19 + V_26 , V_27 ) ;
F_16 ( V_29 , ( void * ) line ) ;
F_10 ( V_29 -> V_35 . V_36 + V_19 + V_40 , 0xff ) ;
F_17 ( 100 ) ;
V_41 ++ ;
return 0 ;
}
static int T_1 F_18 ( void )
{
static int V_42 ;
#ifdef F_3
int line ;
unsigned long V_43 ;
struct V_32 V_33 ;
struct V_44 * V_3 ;
int V_45 ;
#endif
if ( V_42 )
return - V_46 ;
V_42 = 1 ;
if ( ! V_47 )
return - V_46 ;
#ifdef F_7
F_19 ( & V_48 ) ;
#endif
#ifdef F_3
if ( V_49 < V_50 ) {
if ( ! V_41 )
return - V_46 ;
return 0 ;
}
for ( V_45 = 1 ; V_45 < 4 ; V_45 ++ ) {
#ifdef F_14
if ( V_45 == 1 )
continue;
#endif
V_3 = F_20 ( sizeof( struct V_44 ) , V_51 ) ;
if ( ! V_3 )
return - V_39 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_43 = ( V_17 + F_5 ( V_45 ) ) ;
V_33 . V_3 . V_6 = V_7 ;
V_33 . V_3 . V_8 = V_9 | V_10 \
| V_11 ;
V_33 . V_3 . V_25 = 0 ;
V_33 . V_3 . V_14 = V_15 * 16 ;
V_33 . V_3 . V_16 = V_43 ;
V_33 . V_3 . V_18 = ( char * ) ( V_43 + V_19 ) ;
V_33 . V_3 . V_20 = 2 ;
line = F_15 ( & V_33 ) ;
if ( line < 0 ) {
F_4 ( V_38 L_10
L_11 , V_45 , V_33 . V_3 . V_25 ) ;
F_21 ( V_3 ) ;
continue;
}
V_3 -> line = line ;
V_3 -> V_52 = V_53 ;
V_53 = V_3 ;
V_41 ++ ;
}
#endif
if ( ! V_41 )
return - V_46 ;
return 0 ;
}
static void T_3 F_22 ( struct V_28 * V_29 )
{
int line ;
line = ( int ) F_23 ( V_29 ) ;
if ( V_29 -> V_35 . V_36 ) {
F_10 ( V_29 -> V_35 . V_36 + V_19 + V_26 , 0 ) ;
}
F_24 ( line ) ;
}
static void T_4 F_25 ( void )
{
#ifdef F_3
struct V_44 * V_3 , * V_54 ;
for ( V_3 = V_53 ; V_3 ; ) {
F_24 ( V_3 -> line ) ;
V_54 = V_3 ;
V_3 = V_3 -> V_52 ;
F_21 ( V_54 ) ;
}
V_53 = NULL ;
#endif
#ifdef F_7
F_26 ( & V_48 ) ;
#endif
}
