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
struct V_15 * V_16 ;
if ( ! F_5 ( V_14 ) )
continue;
V_16 = F_6 ( V_14 ) ;
if ( ! V_16 || V_16 -> V_17 != V_18 )
continue;
if ( F_7 ( V_19 , V_14 ) ) {
V_11 = V_20 ;
break;
}
V_16 -> V_17 = V_21 ;
V_5 [ V_10 ] = V_14 ;
if ( ++ V_10 >= F_8 ( V_5 ) ) {
V_11 = V_22 ;
break;
}
}
F_9 ( & V_3 -> V_13 ) ;
while ( V_10 )
F_10 ( V_5 [ -- V_10 ] ) ;
return V_11 ;
}
static void F_11 ( struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_12 ( V_24 , struct V_25 , V_27 . V_24 ) ;
int V_28 , V_29 = - 1 ;
struct V_2 * V_3 ;
F_13 () ;
F_14 (cpu) {
enum V_1 V_11 ;
V_3 = F_15 ( V_26 -> V_30 , V_28 ) ;
V_11 = F_1 ( V_3 ) ;
switch ( V_11 ) {
case V_20 :
V_29 = V_31 ;
goto V_32;
case V_22 :
V_29 = 0 ;
break;
case V_12 :
break;
}
}
V_32:
F_16 () ;
V_26 -> V_33 = V_29 > 0 ;
if ( V_29 >= 0 )
F_17 ( & V_26 -> V_27 , V_29 ) ;
}
int F_18 ( unsigned int V_34 , struct V_4 * V_14 ,
T_1 V_35 , int V_36 )
{
int V_11 = 0 ;
struct V_37 * V_37 = F_19 ( V_14 ) ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
F_20 () ;
V_39 = F_21 ( V_37 -> V_14 . V_40 ) ;
if ( ! V_39 )
goto V_41;
V_16 = F_6 ( V_14 ) ;
if ( ! V_16 )
goto V_41;
if ( F_5 ( V_14 ) ) {
struct V_42 V_43 = {
. V_14 = V_14 ,
. V_35 = V_16 -> V_35 ? V_16 -> V_35 : V_35 ,
. V_36 = V_36
} ;
unsigned long V_44 = V_16 -> V_35 ? 0 : V_16 -> V_44 ;
if ( ! ( ( V_34 | V_44 ) & V_16 -> V_45 ) )
goto V_41;
V_11 = V_39 -> V_46 ( V_34 | V_44 , & V_43 ) ;
if ( F_22 ( V_11 < 0 || V_44 ) ) {
F_23 ( & V_14 -> V_13 ) ;
if ( V_11 < 0 ) {
if ( V_34 & ( 1 << V_19 ) ) {
if ( V_16 -> V_35 == 0 && V_35 != 0 )
V_16 -> V_35 = V_35 ;
V_16 -> V_17 = V_18 ;
} else {
V_16 -> V_44 |= V_34 ;
}
} else {
V_16 -> V_44 &= ~ V_44 ;
}
F_24 ( & V_14 -> V_13 ) ;
}
}
V_41:
F_25 () ;
return V_11 ;
}
void F_26 ( struct V_4 * V_14 )
{
struct V_37 * V_37 = F_19 ( V_14 ) ;
unsigned long V_47 , V_44 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
struct V_42 V_43 ;
int V_11 ;
F_20 () ;
V_39 = F_21 ( V_37 -> V_14 . V_40 ) ;
if ( V_39 == NULL )
goto V_41;
V_16 = F_6 ( V_14 ) ;
if ( V_16 == NULL )
goto V_41;
V_47 = F_27 ( & V_16 -> V_48 , 0 ) ;
if ( ! F_5 ( V_14 ) || F_28 ( V_14 ) || ! V_47 )
goto V_41;
V_44 = V_16 -> V_44 ;
if ( ! ( ( V_47 | V_44 ) & V_16 -> V_45 ) )
goto V_41;
V_43 . V_14 = V_14 ;
V_43 . V_35 = 0 ;
V_43 . V_36 = 0 ;
V_11 = V_39 -> V_46 ( V_47 | V_44 , & V_43 ) ;
if ( F_29 ( V_11 >= 0 && ! V_44 ) )
goto V_41;
F_23 ( & V_14 -> V_13 ) ;
if ( V_11 < 0 )
V_16 -> V_44 |= V_47 ;
else
V_16 -> V_44 &= ~ V_44 ;
F_24 ( & V_14 -> V_13 ) ;
V_41:
F_25 () ;
}
void F_30 ( enum V_49 V_50 ,
struct V_51 * exp ,
T_1 V_35 , int V_36 )
{
struct V_37 * V_37 = F_31 ( exp ) ;
struct V_52 * V_39 ;
struct V_15 * V_16 ;
F_20 () ;
V_39 = F_21 ( V_37 -> V_14 . V_53 ) ;
if ( ! V_39 )
goto V_41;
V_16 = F_6 ( exp -> V_54 ) ;
if ( ! V_16 )
goto V_41;
if ( V_16 -> V_55 & ( 1 << V_50 ) ) {
struct V_56 V_43 = {
. exp = exp ,
. V_35 = V_35 ,
. V_36 = V_36
} ;
V_39 -> V_46 ( 1 << V_50 , & V_43 ) ;
}
V_41:
F_25 () ;
}
int F_32 ( struct V_37 * V_37 ,
struct V_38 * V_57 )
{
int V_11 ;
struct V_38 * V_39 ;
F_33 ( & V_58 ) ;
V_39 = F_34 ( V_37 -> V_14 . V_40 ,
F_35 ( & V_58 ) ) ;
if ( V_39 != NULL ) {
V_11 = - V_59 ;
goto V_41;
}
F_36 ( V_37 -> V_14 . V_40 , V_57 ) ;
V_11 = 0 ;
V_41:
F_37 ( & V_58 ) ;
return V_11 ;
}
void F_38 ( struct V_37 * V_37 ,
struct V_38 * V_57 )
{
struct V_38 * V_39 ;
F_33 ( & V_58 ) ;
V_39 = F_34 ( V_37 -> V_14 . V_40 ,
F_35 ( & V_58 ) ) ;
F_39 ( V_39 != V_57 ) ;
F_40 ( V_37 -> V_14 . V_40 , NULL ) ;
F_37 ( & V_58 ) ;
}
int F_41 ( struct V_37 * V_37 ,
struct V_52 * V_57 )
{
int V_11 ;
struct V_52 * V_39 ;
F_33 ( & V_58 ) ;
V_39 = F_34 ( V_37 -> V_14 . V_53 ,
F_35 ( & V_58 ) ) ;
if ( V_39 != NULL ) {
V_11 = - V_59 ;
goto V_41;
}
F_36 ( V_37 -> V_14 . V_53 , V_57 ) ;
V_11 = 0 ;
V_41:
F_37 ( & V_58 ) ;
return V_11 ;
}
void F_42 ( struct V_37 * V_37 ,
struct V_52 * V_57 )
{
struct V_52 * V_39 ;
F_33 ( & V_58 ) ;
V_39 = F_34 ( V_37 -> V_14 . V_53 ,
F_35 ( & V_58 ) ) ;
F_39 ( V_39 != V_57 ) ;
F_40 ( V_37 -> V_14 . V_53 , NULL ) ;
F_37 ( & V_58 ) ;
}
static int F_43 ( struct V_37 * V_37 )
{
struct V_60 * V_61 ;
V_61 = F_44 ( V_62 , sizeof( V_62 ) ,
V_63 ) ;
if ( ! V_61 )
goto V_32;
V_61 [ 0 ] . V_64 = & V_37 -> V_14 . V_65 ;
if ( V_37 -> V_66 != & V_67 )
V_61 [ 0 ] . V_68 = NULL ;
V_37 -> V_14 . V_69 =
F_45 ( V_37 , L_1 , V_61 ) ;
if ( ! V_37 -> V_14 . V_69 ) {
F_46 ( V_70 L_2 ) ;
goto V_71;
}
return 0 ;
V_71:
F_47 ( V_61 ) ;
V_32:
return - V_72 ;
}
static void F_48 ( struct V_37 * V_37 )
{
struct V_60 * V_61 ;
V_61 = V_37 -> V_14 . V_69 -> V_73 ;
F_49 ( V_37 -> V_14 . V_69 ) ;
F_47 ( V_61 ) ;
}
static int F_43 ( struct V_37 * V_37 )
{
return 0 ;
}
static void F_48 ( struct V_37 * V_37 )
{
}
int F_50 ( struct V_37 * V_37 )
{
V_37 -> V_14 . V_65 = V_74 ;
F_51 ( & V_37 -> V_14 . V_27 , F_11 ) ;
return F_43 ( V_37 ) ;
}
void F_52 ( struct V_37 * V_37 )
{
F_53 ( & V_37 -> V_14 . V_27 ) ;
F_48 ( V_37 ) ;
}
int F_54 ( void )
{
int V_11 = F_55 ( & V_75 ) ;
if ( V_11 < 0 )
F_56 ( L_3 ) ;
return V_11 ;
}
void F_57 ( void )
{
F_58 ( & V_75 ) ;
}
