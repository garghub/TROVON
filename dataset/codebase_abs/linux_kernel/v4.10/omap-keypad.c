static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( 1 , V_3 + V_4 ) ;
F_3 ( & V_5 ) ;
return V_6 ;
}
static void F_4 ( unsigned long V_7 )
{
F_3 ( & V_5 ) ;
}
static void F_5 ( struct V_8 * V_8 , unsigned char * V_9 )
{
int V_10 = 0 ;
F_2 ( 1 , V_3 + V_4 ) ;
F_2 ( 0xff , V_3 + V_11 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
F_2 ( ~ ( 1 << V_10 ) & 0xff ,
V_3 + V_11 ) ;
F_6 ( V_8 -> V_13 ) ;
V_9 [ V_10 ] = ~ F_7 ( V_3 +
V_14 ) & 0xff ;
}
F_2 ( 0x00 , V_3 + V_11 ) ;
F_6 ( 2 ) ;
}
static void F_8 ( unsigned long V_7 )
{
struct V_8 * V_15 = (struct V_8 * ) V_7 ;
unsigned short * V_16 = V_15 -> V_17 -> V_18 ;
unsigned int V_19 = F_9 ( V_15 -> V_12 ) ;
unsigned char V_20 [ 8 ] , V_21 , V_22 = 0 ;
int V_10 , V_23 ;
F_5 ( V_15 , V_20 ) ;
for ( V_10 = 0 ; V_10 < V_15 -> V_12 ; V_10 ++ ) {
V_21 = V_20 [ V_10 ] ^ V_24 [ V_10 ] ;
V_22 |= V_20 [ V_10 ] ;
if ( V_21 == 0 )
continue;
for ( V_23 = 0 ; V_23 < V_15 -> V_25 ; V_23 ++ ) {
int V_26 ;
if ( ! ( V_21 & ( 1 << V_23 ) ) )
continue;
#ifdef F_10
F_11 ( V_27 L_1 , V_10 ,
V_23 , ( V_20 [ V_10 ] & ( 1 << V_23 ) ) ?
L_2 : L_3 ) ;
#else
V_26 = V_16 [ F_12 ( V_23 , V_10 , V_19 ) ] ;
if ( ! ( V_28 == ( V_26 & V_29 ) ||
V_28 == - 1 ) )
continue;
V_28 = V_26 & V_29 ;
F_13 ( V_15 -> V_17 , V_26 & ~ V_29 ,
V_20 [ V_10 ] & ( 1 << V_23 ) ) ;
#endif
}
}
F_14 ( V_15 -> V_17 ) ;
memcpy ( V_24 , V_20 , sizeof( V_24 ) ) ;
if ( V_22 ) {
F_15 ( & V_15 -> V_30 , V_31 + V_32 / 20 ) ;
} else {
F_2 ( 0 , V_3 + V_4 ) ;
V_28 = - 1 ;
}
}
static T_2 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return sprintf ( V_37 , L_4 , V_38 ) ;
}
static T_2 F_17 ( struct V_33 * V_34 , struct V_35 * V_36 ,
const char * V_37 , T_3 V_39 )
{
struct V_8 * V_8 = F_18 ( V_34 ) ;
int V_9 ;
if ( sscanf ( V_37 , L_5 , & V_9 ) != 1 )
return - V_40 ;
if ( ( V_9 != 1 ) && ( V_9 != 0 ) )
return - V_40 ;
F_19 ( & V_41 ) ;
if ( V_9 != V_38 ) {
if ( V_9 )
F_20 ( V_8 -> V_1 ) ;
else
F_21 ( V_8 -> V_1 ) ;
V_38 = V_9 ;
}
F_22 ( & V_41 ) ;
return F_23 ( V_37 , V_39 ) ;
}
static int F_24 ( struct V_42 * V_43 )
{
struct V_8 * V_8 ;
struct V_44 * V_44 ;
struct V_45 * V_46 = F_25 ( & V_43 -> V_34 ) ;
int V_47 , V_48 , V_49 , V_50 ;
unsigned int V_19 , V_51 ;
if ( ! V_46 -> V_25 || ! V_46 -> V_12 || ! V_46 -> V_52 ) {
F_11 ( V_53 L_6 ) ;
return - V_40 ;
}
V_19 = F_9 ( V_46 -> V_12 ) ;
V_51 = V_46 -> V_25 << V_19 ;
V_8 = F_26 ( sizeof( struct V_8 ) +
V_51 * sizeof( unsigned short ) , V_54 ) ;
V_44 = F_27 () ;
if ( ! V_8 || ! V_44 ) {
F_28 ( V_8 ) ;
F_29 ( V_44 ) ;
return - V_55 ;
}
F_30 ( V_43 , V_8 ) ;
V_8 -> V_17 = V_44 ;
F_2 ( 1 , V_3 + V_4 ) ;
if ( V_46 -> V_13 )
V_8 -> V_13 = V_46 -> V_13 ;
if ( V_46 -> V_56 && V_46 -> V_57 ) {
V_56 = V_46 -> V_56 ;
V_57 = V_46 -> V_57 ;
}
V_8 -> V_25 = V_46 -> V_25 ;
V_8 -> V_12 = V_46 -> V_12 ;
V_48 = 0 ;
V_49 = 0 ;
F_31 ( & V_8 -> V_30 , F_4 , ( unsigned long ) V_8 ) ;
V_5 . V_7 = ( unsigned long ) V_8 ;
F_32 ( & V_5 ) ;
V_50 = F_33 ( & V_43 -> V_34 , & V_58 ) ;
if ( V_50 < 0 )
goto V_59;
V_44 -> V_60 = L_7 ;
V_44 -> V_61 = L_8 ;
V_44 -> V_34 . V_62 = & V_43 -> V_34 ;
V_44 -> V_63 . V_64 = V_65 ;
V_44 -> V_63 . V_66 = 0x0001 ;
V_44 -> V_63 . V_67 = 0x0001 ;
V_44 -> V_63 . V_68 = 0x0100 ;
if ( V_46 -> V_69 )
F_34 ( V_70 , V_44 -> V_71 ) ;
V_50 = F_35 ( V_46 -> V_52 , NULL ,
V_46 -> V_25 , V_46 -> V_12 ,
V_8 -> V_72 , V_44 ) ;
if ( V_50 < 0 )
goto V_73;
V_50 = F_36 ( V_8 -> V_17 ) ;
if ( V_50 < 0 ) {
F_11 ( V_53 L_9 ) ;
goto V_73;
}
if ( V_46 -> V_74 )
F_2 ( 0xff , V_3 + V_75 ) ;
F_5 ( V_8 , V_24 ) ;
V_8 -> V_1 = F_37 ( V_43 , 0 ) ;
if ( V_8 -> V_1 >= 0 ) {
if ( F_38 ( V_8 -> V_1 , F_1 , 0 ,
L_7 , V_8 ) < 0 )
goto V_76;
}
F_2 ( 0 , V_3 + V_4 ) ;
return 0 ;
V_76:
F_39 ( V_8 -> V_17 ) ;
V_44 = NULL ;
V_73:
F_40 ( & V_43 -> V_34 , & V_58 ) ;
V_59:
for ( V_47 = V_49 - 1 ; V_47 >= 0 ; V_47 -- )
F_41 ( V_56 [ V_47 ] ) ;
for ( V_47 = V_48 - 1 ; V_47 >= 0 ; V_47 -- )
F_41 ( V_57 [ V_47 ] ) ;
F_28 ( V_8 ) ;
F_29 ( V_44 ) ;
return - V_40 ;
}
static int F_42 ( struct V_42 * V_43 )
{
struct V_8 * V_8 = F_43 ( V_43 ) ;
F_44 ( & V_5 ) ;
F_2 ( 1 , V_3 + V_4 ) ;
F_45 ( V_8 -> V_1 , V_8 ) ;
F_46 ( & V_8 -> V_30 ) ;
F_47 ( & V_5 ) ;
F_39 ( V_8 -> V_17 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
