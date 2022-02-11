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
if ( V_9 -> V_24 && F_4 ( V_25 ) )
V_19 = (* V_9 -> V_24 )() ;
F_5 ( & V_21 ,
V_9 -> V_18 , V_9 -> V_26 ) ;
F_5 ( & V_21 ,
V_9 -> V_15 , V_9 -> V_27 ) ;
F_6 ( & V_21 , V_9 -> V_28 ) ;
V_23 = F_7 ( NULL , V_19 , V_9 -> V_29 , V_9 ,
& V_21 ) ;
V_9 -> V_23 = V_23 ;
V_20 = V_20 || F_8 ( V_23 ) ;
F_9 ( V_9 , V_20 ) ;
if ( ! V_23 ) {
F_10 ( & V_21 ) ;
return;
}
V_19 = V_23 -> V_30 . V_31 + 1 ;
if ( V_19 > 224 ) {
V_19 = 0 ;
V_20 = 1 ;
}
if ( F_4 ( V_25 ) ) {
F_11 ( V_23 ) ;
} else {
F_12 ( V_23 ) ;
F_13 ( V_23 ) ;
}
F_14 ( V_23 ) ;
}
void F_15 ( struct V_8 * V_9 , struct V_32 * V_33 )
{
struct V_34 V_35 ;
struct V_36 V_37 ;
F_16 ( L_1 , V_33 -> V_38 ) ;
V_9 -> V_39 = V_33 ;
if ( F_17 ( & V_37 , V_33 ) )
return;
F_18 (&parser, &range) {
struct V_2 * V_3 = NULL ;
switch ( V_35 . V_12 & V_40 ) {
case V_13 :
F_16 ( L_2 ,
V_35 . V_41 ,
V_35 . V_41 + V_35 . V_4 - 1 ) ;
V_9 -> V_42 =
( unsigned long ) F_19 ( V_35 . V_41 ,
V_35 . V_4 ) ;
V_3 = V_9 -> V_15 ;
break;
case V_16 :
F_16 ( L_3 ,
V_35 . V_41 ,
V_35 . V_41 + V_35 . V_4 - 1 ) ;
V_3 = V_9 -> V_18 ;
break;
}
if ( V_3 != NULL )
F_20 ( & V_35 , V_33 , V_3 ) ;
}
}
struct V_32 * F_21 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_10 ;
return F_22 ( V_9 -> V_39 ) ;
}
void F_23 ( struct V_8 * V_9 )
{
struct V_2 * V_43 ;
V_43 = V_9 -> V_18 -> V_43 ;
if ( ! V_43 )
V_43 = & V_44 ;
if ( F_24 ( V_43 , V_9 -> V_18 ) < 0 )
goto V_45;
V_43 = V_9 -> V_15 -> V_43 ;
if ( ! V_43 )
V_43 = & V_46 ;
if ( F_24 ( V_43 , V_9 -> V_15 ) < 0 ) {
F_25 ( V_9 -> V_18 ) ;
goto V_45;
}
F_26 ( & V_9 -> V_47 ) ;
F_27 ( & V_9 -> V_47 , & V_48 ) ;
if ( ! V_9 -> V_42 ) {
F_28 ( V_49
L_4 ) ;
}
if ( V_50 ) {
F_29 ( & V_51 ) ;
F_2 ( V_9 ) ;
F_30 ( & V_51 ) ;
}
return;
V_45:
F_28 ( V_49
L_5 ) ;
}
static int T_2 F_31 ( void )
{
struct V_8 * V_9 ;
F_32 (hose, &controllers, list)
F_2 ( V_9 ) ;
F_33 ( V_52 , V_53 ) ;
V_50 = 1 ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , int V_54 )
{
T_3 V_55 , V_56 ;
int V_57 ;
struct V_2 * V_58 ;
F_35 ( V_7 , V_59 , & V_55 ) ;
V_56 = V_55 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( ! ( V_54 & ( 1 << V_57 ) ) )
continue;
V_58 = & V_7 -> V_2 [ V_57 ] ;
if ( ! ( V_58 -> V_12 & ( V_13 | V_16 ) ) )
continue;
if ( ( V_57 == V_61 ) &&
( ! ( V_58 -> V_12 & V_62 ) ) )
continue;
if ( ! V_58 -> V_11 && V_58 -> V_31 ) {
F_28 ( V_63 L_6
L_7 ,
F_36 ( V_7 ) ) ;
return - V_64 ;
}
if ( V_58 -> V_12 & V_13 )
V_55 |= V_65 ;
if ( V_58 -> V_12 & V_16 )
V_55 |= V_66 ;
}
if ( V_55 != V_56 ) {
F_28 ( L_8 ,
F_36 ( V_7 ) , V_56 , V_55 ) ;
F_37 ( V_7 , V_59 , V_55 ) ;
}
return 0 ;
}
int F_38 ( struct V_6 * V_7 , int V_54 )
{
int V_67 ;
if ( ( V_67 = F_34 ( V_7 , V_54 ) ) < 0 )
return V_67 ;
return F_39 ( V_7 ) ;
}
void F_40 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = V_23 -> V_68 ;
if ( F_4 ( V_25 ) && V_7 &&
( V_7 -> V_69 >> 8 ) == V_70 ) {
F_41 ( V_23 ) ;
}
}
char * T_2 F_42 ( char * V_71 )
{
if ( V_72 )
return V_72 ( V_71 ) ;
return V_71 ;
}
