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
F_4 ( L_1 ) ;
V_3 . V_13 = V_14 * 16 ;
V_3 . V_15 = ( V_16 + F_5 ( 1 ) ) ;
V_3 . V_17 = ( char * ) ( V_3 . V_15 + V_18 ) ;
V_3 . V_19 = 2 ;
F_6 ( L_2 , V_3 . line , L_3 ) ;
#else
F_7 ( L_4 ) ;
return 0 ;
#endif
} else {
#ifdef F_8
unsigned long V_20 = F_9 ( V_1 ) ;
if ( ! V_20 )
return 0 ;
F_4 ( L_5 , V_1 ) ;
V_3 . V_13 = V_21 * 16 ;
V_3 . V_15 = ( V_20 + V_22 ) ;
V_3 . V_17 = ( char * ) ( V_3 . V_15 + V_18 ) ;
V_3 . V_19 = 1 ;
V_3 . V_23 = F_10 ( V_20 + V_18 ) ;
F_11 ( V_20 + V_18 + V_24 , V_25 ) ;
if ( F_12 ( V_20 + V_18 ) & 0x80 )
F_6 ( L_2 , V_3 . line , L_3 ) ;
#else
F_7 ( L_6 ) ;
return 0 ;
#endif
}
if ( F_13 ( & V_3 ) < 0 )
F_7 ( L_7 , V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_31 V_32 ;
int line ;
#ifdef F_15
if ( V_4 == V_28 -> V_1 ) {
return 0 ;
}
#endif
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_3 . V_6 = V_7 ;
V_32 . V_3 . V_8 = V_9 | V_10 | V_11 ;
V_32 . V_3 . V_23 = V_28 -> V_33 ;
V_32 . V_3 . V_13 = V_21 * 16 ;
V_32 . V_3 . V_15 = ( V_28 -> V_34 . V_35 + V_22 ) ;
V_32 . V_3 . V_17 = ( char * ) ( V_32 . V_3 . V_15 + V_18 ) ;
V_32 . V_3 . V_19 = 1 ;
V_32 . V_3 . V_36 = & V_28 -> V_36 ;
line = F_16 ( & V_32 ) ;
if ( line < 0 ) {
F_17 ( & V_28 -> V_36 ,
L_8 ,
V_28 -> V_1 , V_32 . V_3 . V_23 ) ;
return - V_37 ;
}
F_11 ( V_28 -> V_34 . V_35 + V_18 + V_24 , V_25 ) ;
F_18 ( V_28 , ( void * ) line ) ;
F_11 ( V_28 -> V_34 . V_35 + V_18 + V_38 , 0xff ) ;
F_19 ( 100 ) ;
V_39 ++ ;
return 0 ;
}
static int T_1 F_20 ( void )
{
static int V_40 ;
#ifdef F_3
int line ;
unsigned long V_41 ;
struct V_31 V_32 ;
struct V_42 * V_3 ;
int V_43 ;
#endif
if ( V_40 )
return - V_44 ;
V_40 = 1 ;
if ( ! V_45 )
return - V_44 ;
#ifdef F_8
F_21 ( & V_46 ) ;
#endif
#ifdef F_3
if ( V_47 < V_48 ) {
if ( ! V_39 )
return - V_44 ;
return 0 ;
}
for ( V_43 = 1 ; V_43 < 4 ; V_43 ++ ) {
#ifdef F_15
if ( V_43 == 1 )
continue;
#endif
V_3 = F_22 ( sizeof( struct V_42 ) , V_49 ) ;
if ( ! V_3 )
return - V_37 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_41 = ( V_16 + F_5 ( V_43 ) ) ;
V_32 . V_3 . V_6 = V_7 ;
V_32 . V_3 . V_8 = V_9 | V_10
| V_11 ;
V_32 . V_3 . V_23 = 0 ;
V_32 . V_3 . V_13 = V_14 * 16 ;
V_32 . V_3 . V_15 = V_41 ;
V_32 . V_3 . V_17 = ( char * ) ( V_41 + V_18 ) ;
V_32 . V_3 . V_19 = 2 ;
line = F_16 ( & V_32 ) ;
if ( line < 0 ) {
F_17 ( V_32 . V_3 . V_36 ,
L_9 ,
V_43 , V_32 . V_3 . V_23 ) ;
F_23 ( V_3 ) ;
continue;
}
V_3 -> line = line ;
V_3 -> V_50 = V_51 ;
V_51 = V_3 ;
V_39 ++ ;
}
#endif
if ( ! V_39 )
return - V_44 ;
return 0 ;
}
static void F_24 ( struct V_27 * V_28 )
{
int line ;
line = ( int ) F_25 ( V_28 ) ;
if ( V_28 -> V_34 . V_35 ) {
F_11 ( V_28 -> V_34 . V_35 + V_18 + V_24 , 0 ) ;
}
F_26 ( line ) ;
}
static void T_2 F_27 ( void )
{
#ifdef F_3
struct V_42 * V_3 , * V_52 ;
for ( V_3 = V_51 ; V_3 ; ) {
F_26 ( V_3 -> line ) ;
V_52 = V_3 ;
V_3 = V_3 -> V_50 ;
F_23 ( V_52 ) ;
}
V_51 = NULL ;
#endif
#ifdef F_8
F_28 ( & V_46 ) ;
#endif
}
