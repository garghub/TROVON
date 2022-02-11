T_1
F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = V_3 -> V_11 ;
if ( V_3 -> V_12 & V_13 ) {
if ( V_11 < V_14 + V_9 -> V_15 -> V_11 )
V_11 = V_14 + V_9 -> V_15 -> V_11 ;
if ( V_11 & 0x300 )
V_11 = ( V_11 + 0x3ff ) & ~ 0x3ff ;
} else if ( V_3 -> V_12 & V_16 ) {
if ( V_11 < V_17 + V_9 -> V_18 -> V_11 )
V_11 = V_17 + V_9 -> V_18 -> V_11 ;
}
return V_11 ;
}
static void F_2 ( struct V_8 * V_9 )
{
static int V_19 ;
static int V_20 ;
F_3 ( V_21 ) ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
V_25 = F_4 ( 0 ) ;
if ( ! V_25 )
return;
if ( V_9 -> V_27 && F_5 ( V_28 ) )
V_19 = (* V_9 -> V_27 )() ;
F_6 ( & V_21 ,
V_9 -> V_18 , V_9 -> V_29 ) ;
F_6 ( & V_21 ,
V_9 -> V_15 , V_9 -> V_30 ) ;
F_7 ( & V_21 , V_9 -> V_31 ) ;
F_8 ( & V_21 , & V_25 -> V_32 ) ;
V_25 -> V_7 . V_33 = NULL ;
V_25 -> V_10 = V_9 ;
V_25 -> V_34 = V_19 ;
V_25 -> V_35 = V_9 -> V_36 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_40 ;
V_26 = F_9 ( V_25 ) ;
if ( V_26 ) {
F_10 ( V_25 ) ;
return;
}
V_9 -> V_23 = V_23 = V_25 -> V_23 ;
V_20 = V_20 || F_11 ( V_23 ) ;
F_12 ( V_9 , V_20 ) ;
V_19 = V_23 -> V_41 . V_42 + 1 ;
if ( V_19 > 224 ) {
V_19 = 0 ;
V_20 = 1 ;
}
if ( F_5 ( V_28 ) ) {
F_13 ( V_23 ) ;
} else {
F_14 ( V_23 ) ;
F_15 ( V_23 ) ;
}
F_16 ( V_23 ) ;
}
void F_17 ( struct V_8 * V_9 , struct V_43 * V_44 )
{
struct V_45 V_46 ;
struct V_47 V_48 ;
F_18 ( L_1 , V_44 ) ;
V_9 -> V_49 = V_44 ;
if ( F_19 ( & V_48 , V_44 ) )
return;
F_20 (&parser, &range) {
struct V_2 * V_3 = NULL ;
switch ( V_46 . V_12 & V_50 ) {
case V_13 :
F_18 ( L_2 ,
V_46 . V_51 ,
V_46 . V_51 + V_46 . V_4 - 1 ) ;
V_9 -> V_52 =
( unsigned long ) F_21 ( V_46 . V_51 ,
V_46 . V_4 ) ;
V_3 = V_9 -> V_15 ;
break;
case V_16 :
F_18 ( L_3 ,
V_46 . V_51 ,
V_46 . V_51 + V_46 . V_4 - 1 ) ;
V_3 = V_9 -> V_18 ;
break;
}
if ( V_3 != NULL )
F_22 ( & V_46 , V_44 , V_3 ) ;
}
}
struct V_43 * F_23 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_10 ;
return F_24 ( V_9 -> V_49 ) ;
}
void F_25 ( struct V_8 * V_9 )
{
struct V_2 * V_33 ;
V_33 = V_9 -> V_18 -> V_33 ;
if ( ! V_33 )
V_33 = & V_53 ;
if ( F_26 ( V_33 , V_9 -> V_18 ) < 0 )
goto V_54;
V_33 = V_9 -> V_15 -> V_33 ;
if ( ! V_33 )
V_33 = & V_55 ;
if ( F_26 ( V_33 , V_9 -> V_15 ) < 0 ) {
F_27 ( V_9 -> V_18 ) ;
goto V_54;
}
F_28 ( & V_9 -> V_56 ) ;
F_29 ( & V_9 -> V_56 , & V_57 ) ;
if ( ! V_9 -> V_52 ) {
F_30 ( V_58
L_4 ) ;
}
if ( V_59 ) {
F_31 ( & V_60 ) ;
F_2 ( V_9 ) ;
F_32 ( & V_60 ) ;
}
return;
V_54:
F_30 ( V_58
L_5 ) ;
}
static int T_2 F_33 ( void )
{
struct V_8 * V_9 ;
F_34 (hose, &controllers, list)
F_2 ( V_9 ) ;
V_59 = 1 ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , int V_61 )
{
T_3 V_62 , V_63 ;
int V_64 ;
struct V_2 * V_65 ;
F_36 ( V_7 , V_66 , & V_62 ) ;
V_63 = V_62 ;
for ( V_64 = 0 ; V_64 < V_67 ; V_64 ++ ) {
if ( ! ( V_61 & ( 1 << V_64 ) ) )
continue;
V_65 = & V_7 -> V_2 [ V_64 ] ;
if ( ! ( V_65 -> V_12 & ( V_13 | V_16 ) ) )
continue;
if ( ( V_64 == V_68 ) &&
( ! ( V_65 -> V_12 & V_69 ) ) )
continue;
if ( ! V_65 -> V_11 && V_65 -> V_42 ) {
F_30 ( V_70 L_6
L_7 ,
F_37 ( V_7 ) ) ;
return - V_71 ;
}
if ( V_65 -> V_12 & V_13 )
V_62 |= V_72 ;
if ( V_65 -> V_12 & V_16 )
V_62 |= V_73 ;
}
if ( V_62 != V_63 ) {
F_30 ( L_8 ,
F_37 ( V_7 ) , V_63 , V_62 ) ;
F_38 ( V_7 , V_66 , V_62 ) ;
}
return 0 ;
}
int F_39 ( struct V_6 * V_7 , int V_61 )
{
int V_74 ;
if ( ( V_74 = F_35 ( V_7 , V_61 ) ) < 0 )
return V_74 ;
return F_40 ( V_7 ) ;
}
void F_41 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = V_23 -> V_75 ;
if ( F_5 ( V_28 ) && V_7 &&
( V_7 -> V_76 >> 8 ) == V_77 ) {
F_42 ( V_23 ) ;
}
}
char * T_2 F_43 ( char * V_78 )
{
if ( V_79 )
return V_79 ( V_78 ) ;
return V_78 ;
}
