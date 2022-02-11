static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_4 -> V_5 & V_6 ) {
return F_2 ( V_4 ) ;
} else {
return F_3 ( V_4 ) ;
}
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_10 == NULL )
return;
F_5 ( V_10 -> V_12 ) ;
}
static int F_6 ( struct V_13 * V_14 , unsigned int V_15 )
{
if ( ! V_16 [ V_15 ] )
return 0 ;
if ( V_1 [ V_15 ] == V_17 ) {
F_7 ( V_14 , L_1 ) ;
return 0 ;
}
if ( V_18 [ V_15 ] == V_19 ) {
F_7 ( V_14 , L_2 ) ;
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
int V_22 ;
V_22 = F_9 ( V_23 [ V_15 ] , V_24 [ V_15 ] , V_25 ,
sizeof( struct V_9 ) , & V_8 ) ;
if ( V_22 < 0 )
return V_22 ;
V_10 = V_8 -> V_11 ;
V_8 -> V_26 = F_4 ;
V_10 -> V_12 = F_10 ( 0x388 , 4 , L_3 ) ;
if ( V_27 [ V_15 ] != V_28 ) {
if ( ( V_22 = F_11 ( V_8 , V_27 [ V_15 ] , V_1 [ V_15 ] ,
F_1 ,
V_18 [ V_15 ] ,
- 1 ,
V_29 ,
& V_4 ) ) < 0 )
goto V_30;
} else {
static unsigned long V_31 [] = {
0x220 , 0x240 , 0x260 ,
} ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_31 ) ; V_32 ++ ) {
V_22 = F_11 ( V_8 , V_31 [ V_32 ] ,
V_1 [ V_15 ] ,
F_1 ,
V_18 [ V_15 ] ,
- 1 ,
V_29 ,
& V_4 ) ;
if ( V_22 >= 0 ) {
V_27 [ V_15 ] = V_31 [ V_32 ] ;
break;
}
}
if ( V_32 >= F_12 ( V_31 ) ) {
V_22 = - V_33 ;
goto V_30;
}
}
V_10 -> V_4 = V_4 ;
if ( V_4 -> V_34 >= V_35 ) {
if ( V_4 -> V_34 == V_36 )
F_13 ( V_37 L_4 ,
V_27 [ V_15 ] ) ;
else
F_13 ( V_37 L_5 ,
V_27 [ V_15 ] ) ;
V_22 = - V_38 ;
goto V_30;
}
if ( ( V_22 = F_14 ( V_4 , 0 , NULL ) ) < 0 )
goto V_30;
if ( ( V_22 = F_15 ( V_4 ) ) < 0 )
goto V_30;
if ( V_4 -> V_34 == V_39 || V_4 -> V_34 == V_40 ) {
if ( ( V_22 = F_16 ( V_8 , V_4 -> V_27 + 8 , 0 ,
V_41 , 1 ,
& V_21 ) ) < 0 ) {
F_13 ( V_37 L_6 , V_4 -> V_27 + 8 ) ;
}
} else {
if ( ( V_22 = F_16 ( V_8 , V_4 -> V_27 , V_4 -> V_27 + 2 ,
V_41 , 1 ,
& V_21 ) ) < 0 ) {
F_13 ( V_37 L_7 ,
V_4 -> V_27 , V_4 -> V_27 + 2 ) ;
}
}
if ( V_22 >= 0 ) {
if ( ( V_22 = F_17 ( V_21 , 0 , 1 , NULL ) ) < 0 )
goto V_30;
}
if ( ( V_22 = F_18 ( V_4 , 0 , NULL ) ) < 0 )
goto V_30;
strcpy ( V_8 -> V_42 , V_4 -> V_34 == V_43 ? L_8 : L_9 ) ;
strcpy ( V_8 -> V_44 , V_4 -> V_45 ) ;
sprintf ( V_8 -> V_46 , L_10 ,
V_4 -> V_45 ,
V_4 -> V_27 ,
V_1 [ V_15 ] , V_18 [ V_15 ] ) ;
F_19 ( V_8 , V_14 ) ;
if ( ( V_22 = F_20 ( V_8 ) ) < 0 )
goto V_30;
F_21 ( V_14 , V_8 ) ;
return 0 ;
V_30:
F_22 ( V_8 ) ;
return V_22 ;
}
static int F_23 ( struct V_13 * V_14 , unsigned int V_15 )
{
F_22 ( F_24 ( V_14 ) ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_15 , unsigned int V_47 ,
T_2 V_48 )
{
struct V_7 * V_8 = F_24 ( V_15 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_3 * V_4 = V_10 -> V_4 ;
F_26 ( V_8 , V_49 ) ;
F_27 ( V_4 -> V_50 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_15 , unsigned int V_47 )
{
struct V_7 * V_8 = F_24 ( V_15 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_3 * V_4 = V_10 -> V_4 ;
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
F_26 ( V_8 , V_51 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_52 , V_53 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_52 ) ;
}
