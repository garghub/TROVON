void F_1 ( struct V_1 * V_2 , enum V_3 type ,
int V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = V_4 ? V_10 : 0 ;
V_2 -> type = type ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
if ( V_2 -> V_13 [ V_11 ] . V_14 != 0 )
return - V_15 ;
}
if ( V_2 -> V_12 ) {
F_6 ( V_2 , 0 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_7 ( V_2 -> V_16 ) ;
V_2 -> V_12 = 0 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_17 ;
F_9 ( & V_2 -> V_5 ) ;
V_17 = F_5 ( V_2 ) ;
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_18 ,
unsigned int V_19 )
{
unsigned int V_20 = F_12 ( V_19 ) ;
unsigned int V_11 ;
void * V_16 = NULL ;
int V_17 ;
if ( V_18 > V_21 )
V_18 = V_21 ;
F_9 ( & V_2 -> V_5 ) ;
if ( ( V_17 = F_5 ( V_2 ) ) < 0 )
goto V_22;
if ( V_18 == 0 )
goto V_22;
for (; V_18 > 0 ; -- V_18 ) {
V_16 = F_13 ( V_18 * V_20 ) ;
if ( V_16 != NULL )
break;
}
if ( V_16 == NULL ) {
V_17 = - V_23 ;
goto V_22;
}
for ( V_11 = 0 ; V_11 < V_18 ; ++ V_11 ) {
memset ( & V_2 -> V_13 [ V_11 ] , 0 , sizeof V_2 -> V_13 [ V_11 ] ) ;
V_2 -> V_13 [ V_11 ] . V_24 . V_25 = V_11 ;
V_2 -> V_13 [ V_11 ] . V_24 . V_26 . V_27 = V_11 * V_20 ;
V_2 -> V_13 [ V_11 ] . V_24 . V_28 = V_19 ;
V_2 -> V_13 [ V_11 ] . V_24 . type = V_2 -> type ;
V_2 -> V_13 [ V_11 ] . V_24 . V_29 = V_30 ;
V_2 -> V_13 [ V_11 ] . V_24 . V_31 = V_32 ;
V_2 -> V_13 [ V_11 ] . V_24 . V_9 = 0 ;
F_14 ( & V_2 -> V_13 [ V_11 ] . V_33 ) ;
}
V_2 -> V_16 = V_16 ;
V_2 -> V_12 = V_18 ;
V_2 -> V_34 = V_20 ;
V_17 = V_18 ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_35 ;
F_9 ( & V_2 -> V_5 ) ;
V_35 = V_2 -> V_12 != 0 ;
F_10 ( & V_2 -> V_5 ) ;
return V_35 ;
}
static void F_16 ( struct V_36 * V_24 ,
struct V_37 * V_38 )
{
memcpy ( V_38 , & V_24 -> V_24 , sizeof *V_38 ) ;
if ( V_24 -> V_14 )
V_38 -> V_9 |= V_39 ;
switch ( V_24 -> V_40 ) {
case V_41 :
case V_42 :
V_38 -> V_9 |= V_43 ;
break;
case V_44 :
case V_45 :
case V_46 :
V_38 -> V_9 |= V_47 ;
break;
case V_48 :
default:
break;
}
}
int F_17 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
int V_17 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
if ( V_38 -> V_25 >= V_2 -> V_12 ) {
V_17 = - V_49 ;
goto V_22;
}
F_16 ( & V_2 -> V_13 [ V_38 -> V_25 ] , V_38 ) ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_36 * V_24 ;
unsigned long V_9 ;
int V_17 = 0 ;
F_19 ( V_50 , L_1 , V_38 -> V_25 ) ;
if ( V_38 -> type != V_2 -> type ||
V_38 -> V_31 != V_32 ) {
F_19 ( V_50 , L_2
L_3 , V_38 -> type ,
V_38 -> V_31 ) ;
return - V_49 ;
}
F_9 ( & V_2 -> V_5 ) ;
if ( V_38 -> V_25 >= V_2 -> V_12 ) {
F_19 ( V_50 , L_4 ) ;
V_17 = - V_49 ;
goto V_22;
}
V_24 = & V_2 -> V_13 [ V_38 -> V_25 ] ;
if ( V_24 -> V_40 != V_48 ) {
F_19 ( V_50 , L_5
L_6 , V_24 -> V_40 ) ;
V_17 = - V_49 ;
goto V_22;
}
if ( V_38 -> type == V_51 &&
V_38 -> V_52 > V_24 -> V_24 . V_28 ) {
F_19 ( V_50 , L_7 ) ;
V_17 = - V_49 ;
goto V_22;
}
F_20 ( & V_2 -> V_6 , V_9 ) ;
if ( V_2 -> V_9 & V_53 ) {
F_21 ( & V_2 -> V_6 , V_9 ) ;
V_17 = - V_54 ;
goto V_22;
}
V_24 -> V_40 = V_44 ;
if ( V_38 -> type == V_55 )
V_24 -> V_24 . V_52 = 0 ;
else
V_24 -> V_24 . V_52 = V_38 -> V_52 ;
F_22 ( & V_24 -> V_56 , & V_2 -> V_7 ) ;
F_22 ( & V_24 -> V_2 , & V_2 -> V_8 ) ;
F_21 ( & V_2 -> V_6 , V_9 ) ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
static int F_23 ( struct V_36 * V_24 , int V_57 )
{
if ( V_57 ) {
return ( V_24 -> V_40 != V_44 &&
V_24 -> V_40 != V_45 &&
V_24 -> V_40 != V_46 )
? 0 : - V_58 ;
}
return F_24 ( V_24 -> V_33 ,
V_24 -> V_40 != V_44 &&
V_24 -> V_40 != V_45 &&
V_24 -> V_40 != V_46 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_37 * V_38 , int V_57 )
{
struct V_36 * V_24 ;
int V_17 = 0 ;
if ( V_38 -> type != V_2 -> type ||
V_38 -> V_31 != V_32 ) {
F_19 ( V_50 , L_2
L_3 , V_38 -> type ,
V_38 -> V_31 ) ;
return - V_49 ;
}
F_9 ( & V_2 -> V_5 ) ;
if ( F_26 ( & V_2 -> V_7 ) ) {
F_19 ( V_50 , L_8 ) ;
V_17 = - V_49 ;
goto V_22;
}
V_24 = F_27 ( & V_2 -> V_7 , struct V_36 , V_56 ) ;
if ( ( V_17 = F_23 ( V_24 , V_57 ) ) < 0 )
goto V_22;
F_19 ( V_50 , L_9 ,
V_24 -> V_24 . V_25 , V_24 -> V_40 , V_24 -> V_24 . V_52 ) ;
switch ( V_24 -> V_40 ) {
case V_41 :
F_19 ( V_50 , L_10
L_11 ) ;
V_17 = - V_59 ;
case V_42 :
V_24 -> V_40 = V_48 ;
break;
case V_48 :
case V_44 :
case V_45 :
case V_46 :
default:
F_19 ( V_50 , L_12
L_13 , V_24 -> V_40 ) ;
V_17 = - V_49 ;
goto V_22;
}
F_28 ( & V_24 -> V_56 ) ;
F_16 ( V_24 , V_38 ) ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
static void F_29 ( struct V_60 * V_61 )
{
struct V_36 * V_13 = V_61 -> V_62 ;
V_13 -> V_14 ++ ;
}
static void F_30 ( struct V_60 * V_61 )
{
struct V_36 * V_13 = V_61 -> V_62 ;
V_13 -> V_14 -- ;
}
int F_31 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_36 * V_63 ( V_13 ) ;
struct V_64 * V_64 ;
unsigned long V_65 , V_66 , V_67 ;
unsigned int V_11 ;
int V_17 = 0 ;
V_66 = V_61 -> V_68 ;
V_67 = V_61 -> V_69 - V_61 -> V_68 ;
F_9 ( & V_2 -> V_5 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_13 = & V_2 -> V_13 [ V_11 ] ;
if ( ( V_13 -> V_24 . V_26 . V_27 >> V_70 ) == V_61 -> V_71 )
break;
}
if ( V_11 == V_2 -> V_12 || F_12 ( V_67 ) != V_2 -> V_34 ) {
V_17 = - V_49 ;
goto V_22;
}
V_61 -> V_72 |= V_73 ;
V_65 = ( unsigned long ) V_2 -> V_16 + V_13 -> V_24 . V_26 . V_27 ;
#ifdef F_32
while ( V_67 > 0 ) {
V_64 = F_33 ( ( void * ) V_65 ) ;
if ( ( V_17 = F_34 ( V_61 , V_66 , V_64 ) ) < 0 )
goto V_22;
V_66 += V_74 ;
V_65 += V_74 ;
V_67 -= V_74 ;
}
#endif
V_61 -> V_75 = & V_76 ;
V_61 -> V_62 = V_13 ;
F_29 ( V_61 ) ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
unsigned int F_35 ( struct V_1 * V_2 , struct V_77 * V_77 ,
T_1 * V_33 )
{
struct V_36 * V_24 ;
unsigned int V_78 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
if ( F_26 ( & V_2 -> V_7 ) ) {
V_78 |= V_79 ;
goto V_22;
}
V_24 = F_27 ( & V_2 -> V_7 , struct V_36 , V_56 ) ;
F_36 ( V_77 , & V_24 -> V_33 , V_33 ) ;
if ( V_24 -> V_40 == V_42 ||
V_24 -> V_40 == V_41 ) {
if ( V_2 -> type == V_55 )
V_78 |= V_80 | V_81 ;
else
V_78 |= V_82 | V_83 ;
}
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_78 ;
}
unsigned long F_37 ( struct V_1 * V_2 ,
unsigned long V_84 )
{
struct V_36 * V_13 ;
unsigned int V_11 ;
unsigned long V_17 ;
F_9 ( & V_2 -> V_5 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_13 = & V_2 -> V_13 [ V_11 ] ;
if ( ( V_13 -> V_24 . V_26 . V_27 >> V_70 ) == V_84 )
break;
}
if ( V_11 == V_2 -> V_12 ) {
V_17 = - V_49 ;
goto V_22;
}
V_17 = ( unsigned long ) V_2 -> V_16 + V_13 -> V_24 . V_26 . V_27 ;
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
int F_38 ( struct V_1 * V_2 , int V_85 )
{
unsigned int V_11 ;
int V_17 = 0 ;
F_9 ( & V_2 -> V_5 ) ;
if ( V_85 ) {
if ( F_39 ( V_2 ) ) {
V_17 = - V_15 ;
goto V_22;
}
V_2 -> V_9 |= V_86 ;
V_2 -> V_87 = 0 ;
} else {
F_6 ( V_2 , 0 ) ;
F_4 ( & V_2 -> V_7 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_12 ; ++ V_11 ) {
V_2 -> V_13 [ V_11 ] . error = 0 ;
V_2 -> V_13 [ V_11 ] . V_40 = V_48 ;
}
V_2 -> V_9 &= ~ V_86 ;
}
V_22:
F_10 ( & V_2 -> V_5 ) ;
return V_17 ;
}
void F_6 ( struct V_1 * V_2 , int V_88 )
{
struct V_36 * V_24 ;
unsigned long V_9 ;
F_20 ( & V_2 -> V_6 , V_9 ) ;
while ( ! F_26 ( & V_2 -> V_8 ) ) {
V_24 = F_27 ( & V_2 -> V_8 , struct V_36 ,
V_2 ) ;
F_28 ( & V_24 -> V_2 ) ;
V_24 -> V_40 = V_41 ;
F_40 ( & V_24 -> V_33 ) ;
}
if ( V_88 )
V_2 -> V_9 |= V_53 ;
F_21 ( & V_2 -> V_6 , V_9 ) ;
}
struct V_36 * F_41 ( struct V_1 * V_2 ,
struct V_36 * V_24 )
{
struct V_36 * V_89 ;
unsigned long V_9 ;
if ( ( V_2 -> V_9 & V_10 ) && V_24 -> error ) {
V_24 -> error = 0 ;
V_24 -> V_40 = V_44 ;
V_24 -> V_24 . V_52 = 0 ;
return V_24 ;
}
F_20 ( & V_2 -> V_6 , V_9 ) ;
F_28 ( & V_24 -> V_2 ) ;
V_24 -> error = 0 ;
V_24 -> V_40 = V_42 ;
if ( ! F_26 ( & V_2 -> V_8 ) )
V_89 = F_27 ( & V_2 -> V_8 , struct V_36 ,
V_2 ) ;
else
V_89 = NULL ;
F_21 ( & V_2 -> V_6 , V_9 ) ;
F_40 ( & V_24 -> V_33 ) ;
return V_89 ;
}
