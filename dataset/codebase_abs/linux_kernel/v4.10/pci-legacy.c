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
F_5 ( & V_21 ,
V_9 -> V_28 , V_9 -> V_29 ) ;
V_23 = F_6 ( NULL , V_19 , V_9 -> V_30 , V_9 ,
& V_21 ) ;
V_9 -> V_23 = V_23 ;
V_20 = V_20 || F_7 ( V_23 ) ;
F_8 ( V_9 , V_20 ) ;
if ( ! V_23 ) {
F_9 ( & V_21 ) ;
return;
}
V_19 = V_23 -> V_31 . V_32 + 1 ;
if ( V_19 > 224 ) {
V_19 = 0 ;
V_20 = 1 ;
}
if ( F_4 ( V_25 ) ) {
F_10 ( V_23 ) ;
} else {
F_11 ( V_23 ) ;
F_12 ( V_23 ) ;
}
F_13 ( V_23 ) ;
}
void F_14 ( struct V_8 * V_9 , struct V_33 * V_34 )
{
struct V_35 V_36 ;
struct V_37 V_38 ;
F_15 ( L_1 , V_34 -> V_39 ) ;
V_9 -> V_40 = V_34 ;
if ( F_16 ( & V_38 , V_34 ) )
return;
F_17 (&parser, &range) {
struct V_2 * V_3 = NULL ;
switch ( V_36 . V_12 & V_41 ) {
case V_13 :
F_15 ( L_2 ,
V_36 . V_42 ,
V_36 . V_42 + V_36 . V_4 - 1 ) ;
V_9 -> V_43 =
( unsigned long ) F_18 ( V_36 . V_42 ,
V_36 . V_4 ) ;
V_3 = V_9 -> V_15 ;
break;
case V_16 :
F_15 ( L_3 ,
V_36 . V_42 ,
V_36 . V_42 + V_36 . V_4 - 1 ) ;
V_3 = V_9 -> V_18 ;
break;
}
if ( V_3 != NULL )
F_19 ( & V_36 , V_34 , V_3 ) ;
}
}
struct V_33 * F_20 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = V_23 -> V_10 ;
return F_21 ( V_9 -> V_40 ) ;
}
void F_22 ( struct V_8 * V_9 )
{
struct V_2 * V_44 ;
V_44 = V_9 -> V_18 -> V_44 ;
if ( ! V_44 )
V_44 = & V_45 ;
if ( F_23 ( V_44 , V_9 -> V_18 ) < 0 )
goto V_46;
V_44 = V_9 -> V_15 -> V_44 ;
if ( ! V_44 )
V_44 = & V_47 ;
if ( F_23 ( V_44 , V_9 -> V_15 ) < 0 ) {
F_24 ( V_9 -> V_18 ) ;
goto V_46;
}
F_25 ( & V_9 -> V_48 ) ;
F_26 ( & V_9 -> V_48 , & V_49 ) ;
if ( ! V_9 -> V_43 ) {
F_27 ( V_50
L_4 ) ;
}
if ( V_51 ) {
F_28 ( & V_52 ) ;
F_2 ( V_9 ) ;
F_29 ( & V_52 ) ;
}
return;
V_46:
F_27 ( V_50
L_5 ) ;
}
static int T_2 F_30 ( void )
{
struct V_8 * V_9 ;
F_31 (hose, &controllers, list)
F_2 ( V_9 ) ;
F_32 ( V_53 , V_54 ) ;
V_51 = 1 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , int V_55 )
{
T_3 V_56 , V_57 ;
int V_58 ;
struct V_2 * V_59 ;
F_34 ( V_7 , V_60 , & V_56 ) ;
V_57 = V_56 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ ) {
if ( ! ( V_55 & ( 1 << V_58 ) ) )
continue;
V_59 = & V_7 -> V_2 [ V_58 ] ;
if ( ! ( V_59 -> V_12 & ( V_13 | V_16 ) ) )
continue;
if ( ( V_58 == V_62 ) &&
( ! ( V_59 -> V_12 & V_63 ) ) )
continue;
if ( ! V_59 -> V_11 && V_59 -> V_32 ) {
F_27 ( V_64 L_6
L_7 ,
F_35 ( V_7 ) ) ;
return - V_65 ;
}
if ( V_59 -> V_12 & V_13 )
V_56 |= V_66 ;
if ( V_59 -> V_12 & V_16 )
V_56 |= V_67 ;
}
if ( V_56 != V_57 ) {
F_27 ( L_8 ,
F_35 ( V_7 ) , V_57 , V_56 ) ;
F_36 ( V_7 , V_60 , V_56 ) ;
}
return 0 ;
}
int F_37 ( struct V_6 * V_7 , int V_55 )
{
int V_68 ;
if ( ( V_68 = F_33 ( V_7 , V_55 ) ) < 0 )
return V_68 ;
return F_38 ( V_7 ) ;
}
void F_39 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = V_23 -> V_69 ;
if ( F_4 ( V_25 ) && V_7 &&
( V_7 -> V_70 >> 8 ) == V_71 ) {
F_40 ( V_23 ) ;
}
}
char * T_2 F_41 ( char * V_72 )
{
if ( V_73 )
return V_73 ( V_72 ) ;
return V_72 ;
}
