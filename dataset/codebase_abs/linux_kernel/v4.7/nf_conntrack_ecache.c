static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 [ 16 ] ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 = 0 ;
enum V_1 V_11 = V_12 ;
F_2 ( & V_3 -> V_13 ) ;
F_3 (h, n, &pcpu->dying, hnnode) {
struct V_4 * V_14 = F_4 ( V_7 ) ;
if ( F_5 ( V_14 ) )
continue;
if ( F_6 ( V_15 , V_14 ) ) {
V_11 = V_16 ;
break;
}
F_7 ( V_17 , & V_14 -> V_18 ) ;
V_5 [ V_10 ] = V_14 ;
if ( ++ V_10 >= F_8 ( V_5 ) ) {
V_11 = V_19 ;
break;
}
}
F_9 ( & V_3 -> V_13 ) ;
while ( V_10 )
F_10 ( V_5 [ -- V_10 ] ) ;
return V_11 ;
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_12 ( V_21 , struct V_22 , V_24 . V_21 ) ;
int V_25 , V_26 = - 1 ;
struct V_2 * V_3 ;
F_13 () ;
F_14 (cpu) {
enum V_1 V_11 ;
V_3 = F_15 ( V_23 -> V_27 , V_25 ) ;
V_11 = F_1 ( V_3 ) ;
switch ( V_11 ) {
case V_16 :
V_26 = V_28 ;
goto V_29;
case V_19 :
V_26 = 0 ;
break;
case V_12 :
break;
}
}
V_29:
F_16 () ;
V_23 -> V_30 = V_26 > 0 ;
if ( V_26 >= 0 )
F_17 ( & V_23 -> V_24 , V_26 ) ;
}
int F_18 ( unsigned int V_31 , struct V_4 * V_14 ,
T_1 V_32 , int V_33 )
{
int V_11 = 0 ;
struct V_34 * V_34 = F_19 ( V_14 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
F_20 () ;
V_36 = F_21 ( V_34 -> V_14 . V_39 ) ;
if ( ! V_36 )
goto V_40;
V_38 = F_22 ( V_14 ) ;
if ( ! V_38 )
goto V_40;
if ( F_23 ( V_14 ) && ! F_5 ( V_14 ) ) {
struct V_41 V_42 = {
. V_14 = V_14 ,
. V_32 = V_38 -> V_32 ? V_38 -> V_32 : V_32 ,
. V_33 = V_33
} ;
unsigned long V_43 = V_38 -> V_32 ? 0 : V_38 -> V_43 ;
if ( ! ( ( V_31 | V_43 ) & V_38 -> V_44 ) )
goto V_40;
V_11 = V_36 -> V_45 ( V_31 | V_43 , & V_42 ) ;
if ( F_24 ( V_11 < 0 || V_43 ) ) {
F_25 ( & V_14 -> V_13 ) ;
if ( V_11 < 0 ) {
if ( V_31 & ( 1 << V_15 ) &&
V_38 -> V_32 == 0 && V_32 != 0 )
V_38 -> V_32 = V_32 ;
else
V_38 -> V_43 |= V_31 ;
} else {
V_38 -> V_43 &= ~ V_43 ;
}
F_26 ( & V_14 -> V_13 ) ;
}
}
V_40:
F_27 () ;
return V_11 ;
}
void F_28 ( struct V_4 * V_14 )
{
struct V_34 * V_34 = F_19 ( V_14 ) ;
unsigned long V_46 , V_43 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_41 V_42 ;
int V_11 ;
F_20 () ;
V_36 = F_21 ( V_34 -> V_14 . V_39 ) ;
if ( V_36 == NULL )
goto V_40;
V_38 = F_22 ( V_14 ) ;
if ( V_38 == NULL )
goto V_40;
V_46 = F_29 ( & V_38 -> V_47 , 0 ) ;
if ( ! F_23 ( V_14 ) || F_5 ( V_14 ) || ! V_46 )
goto V_40;
V_43 = V_38 -> V_43 ;
if ( ! ( ( V_46 | V_43 ) & V_38 -> V_44 ) )
goto V_40;
V_42 . V_14 = V_14 ;
V_42 . V_32 = 0 ;
V_42 . V_33 = 0 ;
V_11 = V_36 -> V_45 ( V_46 | V_43 , & V_42 ) ;
if ( F_30 ( V_11 >= 0 && ! V_43 ) )
goto V_40;
F_25 ( & V_14 -> V_13 ) ;
if ( V_11 < 0 )
V_38 -> V_43 |= V_46 ;
else
V_38 -> V_43 &= ~ V_43 ;
F_26 ( & V_14 -> V_13 ) ;
V_40:
F_27 () ;
}
void F_31 ( enum V_48 V_49 ,
struct V_50 * exp ,
T_1 V_32 , int V_33 )
{
struct V_34 * V_34 = F_32 ( exp ) ;
struct V_51 * V_36 ;
struct V_37 * V_38 ;
F_20 () ;
V_36 = F_21 ( V_34 -> V_14 . V_52 ) ;
if ( ! V_36 )
goto V_40;
V_38 = F_22 ( exp -> V_53 ) ;
if ( ! V_38 )
goto V_40;
if ( V_38 -> V_54 & ( 1 << V_49 ) ) {
struct V_55 V_42 = {
. exp = exp ,
. V_32 = V_32 ,
. V_33 = V_33
} ;
V_36 -> V_45 ( 1 << V_49 , & V_42 ) ;
}
V_40:
F_27 () ;
}
int F_33 ( struct V_34 * V_34 ,
struct V_35 * V_56 )
{
int V_11 ;
struct V_35 * V_36 ;
F_34 ( & V_57 ) ;
V_36 = F_35 ( V_34 -> V_14 . V_39 ,
F_36 ( & V_57 ) ) ;
if ( V_36 != NULL ) {
V_11 = - V_58 ;
goto V_40;
}
F_37 ( V_34 -> V_14 . V_39 , V_56 ) ;
V_11 = 0 ;
V_40:
F_38 ( & V_57 ) ;
return V_11 ;
}
void F_39 ( struct V_34 * V_34 ,
struct V_35 * V_56 )
{
struct V_35 * V_36 ;
F_34 ( & V_57 ) ;
V_36 = F_35 ( V_34 -> V_14 . V_39 ,
F_36 ( & V_57 ) ) ;
F_40 ( V_36 != V_56 ) ;
F_41 ( V_34 -> V_14 . V_39 , NULL ) ;
F_38 ( & V_57 ) ;
}
int F_42 ( struct V_34 * V_34 ,
struct V_51 * V_56 )
{
int V_11 ;
struct V_51 * V_36 ;
F_34 ( & V_57 ) ;
V_36 = F_35 ( V_34 -> V_14 . V_52 ,
F_36 ( & V_57 ) ) ;
if ( V_36 != NULL ) {
V_11 = - V_58 ;
goto V_40;
}
F_37 ( V_34 -> V_14 . V_52 , V_56 ) ;
V_11 = 0 ;
V_40:
F_38 ( & V_57 ) ;
return V_11 ;
}
void F_43 ( struct V_34 * V_34 ,
struct V_51 * V_56 )
{
struct V_51 * V_36 ;
F_34 ( & V_57 ) ;
V_36 = F_35 ( V_34 -> V_14 . V_52 ,
F_36 ( & V_57 ) ) ;
F_40 ( V_36 != V_56 ) ;
F_41 ( V_34 -> V_14 . V_52 , NULL ) ;
F_38 ( & V_57 ) ;
}
static int F_44 ( struct V_34 * V_34 )
{
struct V_59 * V_60 ;
V_60 = F_45 ( V_61 , sizeof( V_61 ) ,
V_62 ) ;
if ( ! V_60 )
goto V_29;
V_60 [ 0 ] . V_63 = & V_34 -> V_14 . V_64 ;
if ( V_34 -> V_65 != & V_66 )
V_60 [ 0 ] . V_67 = NULL ;
V_34 -> V_14 . V_68 =
F_46 ( V_34 , L_1 , V_60 ) ;
if ( ! V_34 -> V_14 . V_68 ) {
F_47 ( V_69 L_2 ) ;
goto V_70;
}
return 0 ;
V_70:
F_48 ( V_60 ) ;
V_29:
return - V_71 ;
}
static void F_49 ( struct V_34 * V_34 )
{
struct V_59 * V_60 ;
V_60 = V_34 -> V_14 . V_68 -> V_72 ;
F_50 ( V_34 -> V_14 . V_68 ) ;
F_48 ( V_60 ) ;
}
static int F_44 ( struct V_34 * V_34 )
{
return 0 ;
}
static void F_49 ( struct V_34 * V_34 )
{
}
int F_51 ( struct V_34 * V_34 )
{
V_34 -> V_14 . V_64 = V_73 ;
F_52 ( & V_34 -> V_14 . V_24 , F_11 ) ;
return F_44 ( V_34 ) ;
}
void F_53 ( struct V_34 * V_34 )
{
F_54 ( & V_34 -> V_14 . V_24 ) ;
F_49 ( V_34 ) ;
}
int F_55 ( void )
{
int V_11 = F_56 ( & V_74 ) ;
if ( V_11 < 0 )
F_57 ( L_3 ) ;
return V_11 ;
}
void F_58 ( void )
{
F_59 ( & V_74 ) ;
}
