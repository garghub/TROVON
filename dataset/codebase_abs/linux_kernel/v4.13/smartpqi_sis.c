static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
V_4 = ( V_3 * V_6 ) + V_7 ;
while ( 1 ) {
V_5 = F_2 ( & V_2 -> V_8 -> V_9 ) ;
if ( V_5 != ~ 0 ) {
if ( V_5 & V_10 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
F_2 (
& V_2 -> V_8 -> V_13 [ 7 ] ) ) ;
return - V_14 ;
}
if ( V_5 & V_15 )
break;
}
if ( F_4 ( V_7 , V_4 ) ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_2 ,
V_3 ) ;
return - V_16 ;
}
F_5 ( V_17 ) ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ,
V_18 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ,
V_19 ) ;
}
bool F_8 ( struct V_1 * V_2 )
{
bool V_20 ;
T_1 V_5 ;
V_5 = F_2 ( & V_2 -> V_8 -> V_9 ) ;
if ( V_5 & V_10 )
V_20 = false ;
else
V_20 = true ;
if ( ! V_20 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
F_2 ( & V_2 -> V_8 -> V_13 [ 7 ] ) ) ;
return V_20 ;
}
bool F_9 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_8 -> V_9 ) &
V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_21 , struct V_22 * V_23 )
{
struct V_24 T_2 * V_8 ;
unsigned int V_25 ;
unsigned long V_4 ;
T_1 V_26 ;
T_1 V_27 ;
V_8 = V_2 -> V_8 ;
F_11 ( V_21 , & V_8 -> V_13 [ 0 ] ) ;
for ( V_25 = 1 ; V_25 <= 4 ; V_25 ++ )
F_11 ( V_23 -> V_28 [ V_25 ] , & V_8 -> V_13 [ V_25 ] ) ;
F_11 ( V_29 ,
& V_8 -> V_30 ) ;
F_11 ( ~ 0 , & V_8 -> V_31 ) ;
F_2 ( & V_8 -> V_31 ) ;
F_11 ( V_32 , & V_8 -> V_33 ) ;
V_4 = ( V_34 * V_6 ) + V_7 ;
while ( 1 ) {
F_5 ( V_35 ) ;
V_26 = F_2 ( & V_8 -> V_36 ) ;
if ( V_26 & V_37 )
break;
if ( F_4 ( V_7 , V_4 ) )
return - V_16 ;
}
V_27 = F_2 ( & V_8 -> V_13 [ 0 ] ) ;
if ( V_27 != V_38 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_3 ,
V_21 , V_27 ) ;
return - V_39 ;
}
V_23 -> V_28 [ 0 ] = V_27 ;
for ( V_25 = 1 ; V_25 < F_12 ( V_23 -> V_28 ) ; V_25 ++ )
V_23 -> V_28 [ V_25 ] = F_2 ( & V_8 -> V_13 [ V_25 ] ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_40 ;
T_1 V_41 ;
T_1 V_42 ;
struct V_22 V_23 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_40 = F_10 ( V_2 , V_43 ,
& V_23 ) ;
if ( V_40 )
return V_40 ;
V_41 = V_23 . V_28 [ 1 ] ;
if ( ! ( V_41 & V_44 ) )
return - V_14 ;
V_42 = V_23 . V_28 [ 4 ] ;
if ( ( V_42 & V_45 ) !=
V_45 )
return - V_14 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_40 ;
struct V_22 V_23 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_40 = F_10 ( V_2 , V_46 ,
& V_23 ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_47 = V_23 . V_28 [ 1 ] ;
V_2 -> V_48 = V_23 . V_28 [ 2 ] ;
V_2 -> V_49 = V_23 . V_28 [ 3 ] ;
V_2 -> V_50 = V_23 . V_28 [ 4 ] ;
V_2 -> V_51 = V_23 . V_28 [ 5 ] ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_40 ;
void * V_52 ;
struct V_53 * V_54 ;
struct V_22 V_23 ;
unsigned long V_55 ;
T_3 V_56 ;
V_52 = F_16 ( sizeof( * V_54 )
+ V_57 - 1 , V_58 ) ;
if ( ! V_52 )
return - V_59 ;
V_54 = F_17 ( V_52 ,
V_57 ) ;
V_55 = ( unsigned long ) V_2 -> V_60 ;
F_18 ( V_61 , & V_54 -> V_62 ) ;
F_18 ( F_19 ( V_55 ) ,
& V_54 -> V_63 ) ;
F_18 ( F_20 ( V_55 ) ,
& V_54 -> V_64 ) ;
F_18 ( V_65 ,
& V_54 -> V_66 ) ;
F_18 ( V_2 -> V_67 ,
& V_54 -> V_68 ) ;
V_56 = F_21 ( V_2 -> V_11 , V_54 ,
sizeof( * V_54 ) , V_69 ) ;
if ( F_22 ( V_2 -> V_11 , V_56 ) ) {
V_40 = - V_59 ;
goto V_70;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_28 [ 1 ] = F_19 ( ( V_71 ) V_56 ) ;
V_23 . V_28 [ 2 ] = F_20 ( ( V_71 ) V_56 ) ;
V_23 . V_28 [ 3 ] = sizeof( * V_54 ) ;
V_40 = F_10 ( V_2 , V_72 ,
& V_23 ) ;
F_23 ( V_2 -> V_11 , V_56 , sizeof( * V_54 ) ,
V_69 ) ;
V_70:
F_24 ( V_52 ) ;
return V_40 ;
}
static void F_25 (
struct V_1 * V_2 , T_1 V_73 )
{
T_1 V_74 ;
unsigned long V_4 ;
V_4 = ( V_75 * V_6 ) + V_7 ;
while ( 1 ) {
V_74 =
F_2 ( & V_2 -> V_8 -> V_33 ) ;
if ( ( V_74 & V_73 ) == 0 )
break;
if ( F_2 ( & V_2 -> V_8 -> V_9 ) &
V_10 )
break;
if ( F_4 ( V_7 , V_4 ) ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_4 ,
V_73 ) ;
break;
}
F_26 ( 1000 , 2000 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
T_1 V_74 ;
V_74 =
F_2 ( & V_2 -> V_8 -> V_33 ) ;
V_74 |= V_76 ;
F_11 ( V_74 ,
& V_2 -> V_8 -> V_33 ) ;
F_25 ( V_2 , V_76 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
T_1 V_74 ;
V_74 =
F_2 ( & V_2 -> V_8 -> V_33 ) ;
V_74 &= ~ V_76 ;
F_11 ( V_74 ,
& V_2 -> V_8 -> V_33 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
T_1 V_74 ;
V_74 =
F_2 ( & V_2 -> V_8 -> V_33 ) ;
V_74 |= V_77 ;
F_11 ( V_74 ,
& V_2 -> V_8 -> V_33 ) ;
F_25 ( V_2 , V_77 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
T_1 V_74 ;
V_74 =
F_2 ( & V_2 -> V_8 -> V_33 ) ;
V_74 &= ~ V_77 ;
F_11 ( V_74 ,
& V_2 -> V_8 -> V_33 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_11 ( V_78 ,
& V_2 -> V_8 -> V_33 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_8 -> V_9 ) &
V_10 )
return;
F_11 ( V_79 ,
& V_2 -> V_8 -> V_33 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_40 ;
unsigned long V_4 ;
struct V_24 T_2 * V_8 ;
T_1 V_26 ;
V_8 = V_2 -> V_8 ;
F_11 ( V_80 ,
& V_8 -> V_33 ) ;
V_40 = 0 ;
V_4 = ( V_81 * V_6 ) + V_7 ;
while ( 1 ) {
V_26 = F_2 ( & V_8 -> V_36 ) ;
if ( ( V_26 & V_80 ) == 0 )
break;
if ( F_4 ( V_7 , V_4 ) ) {
V_40 = - V_16 ;
break;
}
}
if ( V_40 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_5 ) ;
return V_40 ;
}
void F_34 ( struct V_1 * V_2 , T_1 V_82 )
{
F_11 ( V_82 , & V_2 -> V_8 -> V_83 ) ;
}
T_1 F_35 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_8 -> V_83 ) ;
}
