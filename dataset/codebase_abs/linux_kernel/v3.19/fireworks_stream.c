static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
enum V_7 V_8 ;
enum V_9 V_10 ;
int V_11 ;
if ( V_4 == & V_2 -> V_12 ) {
V_6 = & V_2 -> V_13 ;
V_8 = V_14 ;
V_10 = V_15 ;
} else {
V_6 = & V_2 -> V_16 ;
V_8 = V_17 ;
V_10 = V_18 ;
}
V_11 = F_2 ( V_6 , V_2 -> V_19 , V_8 , 0 ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_3 ( V_4 , V_2 -> V_19 , V_10 , V_21 ) ;
if ( V_11 < 0 ) {
F_4 ( V_4 ) ;
F_5 ( V_6 ) ;
}
V_20:
return V_11 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
if ( V_4 == & V_2 -> V_12 )
F_9 ( & V_2 -> V_13 ) ;
else
F_9 ( & V_2 -> V_16 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_22 )
{
struct V_5 * V_6 ;
unsigned int V_23 , V_24 , V_25 ;
int V_11 ;
V_11 = F_11 ( V_22 , & V_23 ) ;
if ( V_11 < 0 )
goto V_20;
if ( V_4 == & V_2 -> V_12 ) {
V_6 = & V_2 -> V_13 ;
V_24 = V_2 -> V_26 [ V_23 ] ;
V_25 = V_2 -> V_27 ;
} else {
V_6 = & V_2 -> V_16 ;
V_24 = V_2 -> V_28 [ V_23 ] ;
V_25 = V_2 -> V_29 ;
}
F_12 ( V_4 , V_22 ,
V_24 , V_25 ) ;
V_11 = F_13 ( V_6 ,
F_14 ( V_4 ) ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_15 ( V_4 ,
V_6 -> V_30 . V_31 ,
V_6 -> V_32 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 , V_4 ) ;
goto V_20;
}
if ( ! F_16 ( V_4 , V_33 ) ) {
F_6 ( V_2 , V_4 ) ;
V_11 = - V_34 ;
}
V_20:
return V_11 ;
}
static void
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_6 ( V_2 , V_4 ) ;
F_4 ( V_4 ) ;
if ( V_4 == & V_2 -> V_12 )
F_5 ( & V_2 -> V_13 ) ;
else
F_5 ( & V_2 -> V_16 ) ;
}
static int
F_18 ( struct V_1 * V_2 , enum V_35 * V_36 )
{
enum V_37 V_38 ;
int V_11 ;
V_11 = F_19 ( V_2 , & V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_38 == V_39 )
return - V_40 ;
* V_36 = V_41 ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_3 * V_42 )
{
struct V_5 * V_6 ;
bool V_43 ;
int V_11 ;
if ( V_42 == & V_2 -> V_12 )
V_6 = & V_2 -> V_13 ;
else
V_6 = & V_2 -> V_16 ;
V_11 = F_21 ( V_6 , & V_43 ) ;
if ( ( V_11 >= 0 ) && V_43 && ! F_22 ( V_42 ) ) {
F_23 ( & V_2 -> V_19 -> V_44 ,
L_1 ,
( V_6 -> V_45 == V_14 ) ? 'o' : 'i' ,
V_6 -> V_46 ) ;
V_11 = - V_47 ;
}
return V_11 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_1 ( V_2 , & V_2 -> V_12 ) ;
if ( V_11 < 0 )
goto V_20;
V_2 -> V_12 . V_48 |= V_49 ;
V_2 -> V_12 . V_48 |= V_50 ;
V_2 -> V_12 . V_48 |= V_51 ;
if ( V_2 -> V_52 )
V_2 -> V_12 . V_48 |= V_53 ;
if ( V_2 -> V_54 == 0x5050000 )
V_2 -> V_12 . V_55 = 8 ;
V_11 = F_1 ( V_2 , & V_2 -> V_56 ) ;
if ( V_11 < 0 ) {
F_17 ( V_2 , & V_2 -> V_12 ) ;
goto V_20;
}
V_11 = F_25 ( V_2 , V_57 ) ;
if ( V_11 < 0 ) {
F_17 ( V_2 , & V_2 -> V_12 ) ;
F_17 ( V_2 , & V_2 -> V_56 ) ;
}
V_20:
return V_11 ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_3 * V_59 , * V_60 ;
T_1 * V_61 ;
enum V_35 V_36 ;
unsigned int V_62 ;
int V_11 = 0 ;
F_27 ( & V_2 -> V_63 ) ;
if ( ( F_28 ( & V_2 -> V_64 ) == 0 ) &&
( F_28 ( & V_2 -> V_65 ) == 0 ) )
goto V_20;
V_11 = F_18 ( V_2 , & V_36 ) ;
if ( V_11 < 0 )
goto V_20;
if ( V_36 == V_41 ) {
V_59 = & V_2 -> V_12 ;
V_60 = & V_2 -> V_56 ;
V_61 = & V_2 -> V_64 ;
} else {
V_59 = & V_2 -> V_56 ;
V_60 = & V_2 -> V_12 ;
V_61 = & V_2 -> V_65 ;
}
V_11 = F_20 ( V_2 , V_59 ) ;
if ( V_11 < 0 )
goto V_20;
if ( F_29 ( V_60 ) )
F_6 ( V_2 , V_60 ) ;
if ( F_29 ( V_59 ) )
F_6 ( V_2 , V_59 ) ;
V_11 = F_30 ( V_2 , & V_62 ) ;
if ( V_11 < 0 )
goto V_20;
if ( V_58 == 0 )
V_58 = V_62 ;
if ( V_58 != V_62 ) {
F_6 ( V_2 , V_60 ) ;
F_6 ( V_2 , V_59 ) ;
}
if ( ! F_22 ( V_59 ) ) {
F_31 ( V_36 , V_59 , V_60 ) ;
V_2 -> V_59 = V_59 ;
V_11 = F_32 ( V_2 , V_58 ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_10 ( V_2 , V_59 , V_58 ) ;
if ( V_11 < 0 ) {
F_23 ( & V_2 -> V_19 -> V_44 ,
L_2 , V_11 ) ;
goto V_20;
}
}
if ( F_28 ( V_61 ) > 0 && ! F_22 ( V_60 ) ) {
V_11 = F_10 ( V_2 , V_60 , V_58 ) ;
if ( V_11 < 0 ) {
F_23 ( & V_2 -> V_19 -> V_44 ,
L_3 , V_11 ) ;
F_6 ( V_2 , V_59 ) ;
}
}
V_20:
F_33 ( & V_2 -> V_63 ) ;
return V_11 ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_59 , * V_60 ;
T_1 * V_66 , * V_61 ;
if ( V_2 -> V_59 == & V_2 -> V_56 ) {
V_60 = & V_2 -> V_12 ;
V_59 = & V_2 -> V_56 ;
V_61 = & V_2 -> V_65 ;
V_66 = & V_2 -> V_64 ;
} else {
V_60 = & V_2 -> V_56 ;
V_59 = & V_2 -> V_12 ;
V_61 = & V_2 -> V_64 ;
V_66 = & V_2 -> V_65 ;
}
F_27 ( & V_2 -> V_63 ) ;
if ( F_28 ( V_61 ) == 0 ) {
F_6 ( V_2 , V_60 ) ;
if ( F_28 ( V_66 ) == 0 )
F_6 ( V_2 , V_59 ) ;
}
F_33 ( & V_2 -> V_63 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( ( F_36 ( & V_2 -> V_13 ) < 0 ) ||
( F_36 ( & V_2 -> V_16 ) < 0 ) ) {
F_27 ( & V_2 -> V_63 ) ;
F_6 ( V_2 , & V_2 -> V_56 ) ;
F_6 ( V_2 , & V_2 -> V_12 ) ;
F_33 ( & V_2 -> V_63 ) ;
} else {
F_37 ( & V_2 -> V_56 ) ;
F_37 ( & V_2 -> V_12 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_63 ) ;
F_17 ( V_2 , & V_2 -> V_56 ) ;
F_17 ( V_2 , & V_2 -> V_12 ) ;
F_33 ( & V_2 -> V_63 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
V_2 -> V_67 = true ;
F_40 ( & V_2 -> V_68 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_11 ;
F_42 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_70 < 0 ) {
V_11 = - V_47 ;
goto V_20;
}
if ( V_2 -> V_70 ++ == 0 )
F_39 ( V_2 ) ;
V_11 = 0 ;
V_20:
F_43 ( & V_2 -> V_69 ) ;
return V_11 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_69 ) ;
if ( F_45 ( V_2 -> V_70 <= 0 ) )
goto V_20;
if ( -- V_2 -> V_70 == 0 )
F_39 ( V_2 ) ;
V_20:
F_43 ( & V_2 -> V_69 ) ;
}
