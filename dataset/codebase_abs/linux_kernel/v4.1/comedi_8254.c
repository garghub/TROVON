static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = ( V_3 * V_2 -> V_5 ) << V_2 -> V_6 ;
unsigned int V_7 ;
switch ( V_2 -> V_5 ) {
default:
case V_8 :
if ( V_2 -> V_9 )
V_7 = F_2 ( V_2 -> V_9 + V_4 ) ;
else
V_7 = F_3 ( V_2 -> V_10 + V_4 ) ;
break;
case V_11 :
if ( V_2 -> V_9 )
V_7 = F_4 ( V_2 -> V_9 + V_4 ) ;
else
V_7 = F_5 ( V_2 -> V_10 + V_4 ) ;
break;
case V_12 :
if ( V_2 -> V_9 )
V_7 = F_6 ( V_2 -> V_9 + V_4 ) ;
else
V_7 = F_7 ( V_2 -> V_10 + V_4 ) ;
break;
}
return V_7 & 0xff ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_7 , unsigned int V_3 )
{
unsigned int V_4 = ( V_3 * V_2 -> V_5 ) << V_2 -> V_6 ;
switch ( V_2 -> V_5 ) {
default:
case V_8 :
if ( V_2 -> V_9 )
F_9 ( V_7 , V_2 -> V_9 + V_4 ) ;
else
F_10 ( V_7 , V_2 -> V_10 + V_4 ) ;
break;
case V_11 :
if ( V_2 -> V_9 )
F_11 ( V_7 , V_2 -> V_9 + V_4 ) ;
else
F_12 ( V_7 , V_2 -> V_10 + V_4 ) ;
break;
case V_12 :
if ( V_2 -> V_9 )
F_13 ( V_7 , V_2 -> V_9 + V_4 ) ;
else
F_14 ( V_7 , V_2 -> V_10 + V_4 ) ;
break;
}
}
unsigned int F_15 ( struct V_1 * V_2 , unsigned int V_13 )
{
unsigned int V_14 ;
if ( V_13 > 2 )
return 0 ;
V_14 = V_15 | F_16 ( V_13 ) ;
F_8 ( V_2 , V_14 , V_16 ) ;
return F_1 ( V_2 , V_13 ) ;
}
unsigned int F_17 ( struct V_1 * V_2 , unsigned int V_13 )
{
unsigned int V_7 ;
if ( V_13 > 2 )
return 0 ;
F_8 ( V_2 , F_18 ( V_13 ) | V_17 ,
V_16 ) ;
V_7 = F_1 ( V_2 , V_13 ) ;
V_7 |= ( F_1 ( V_2 , V_13 ) << 8 ) ;
return V_7 ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned int V_13 , unsigned int V_7 )
{
unsigned int V_18 ;
if ( V_13 > 2 )
return;
if ( V_7 > 0xffff )
return;
V_18 = V_7 & 0xff ;
F_8 ( V_2 , V_18 , V_13 ) ;
V_18 = ( V_7 >> 8 ) & 0xff ;
F_8 ( V_2 , V_18 , V_13 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_19 )
{
unsigned int V_18 ;
if ( V_13 > 2 )
return - V_20 ;
if ( V_19 > ( V_21 | V_22 ) )
return - V_20 ;
V_18 = F_18 ( V_13 ) |
V_23 |
V_19 ;
F_8 ( V_2 , V_18 , V_16 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_7 , unsigned int V_19 )
{
if ( V_13 > 2 )
return - V_20 ;
if ( V_7 > 0xffff )
return - V_20 ;
if ( V_19 > ( V_21 | V_22 ) )
return - V_20 ;
F_20 ( V_2 , V_13 , V_19 ) ;
F_19 ( V_2 , V_13 , V_7 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_24 ,
unsigned int V_25 ,
bool V_26 )
{
unsigned int V_19 ;
if ( V_24 > 2 || V_25 > 2 || V_24 == V_25 )
return;
if ( V_26 )
V_19 = V_27 | V_28 ;
else
V_19 = V_29 | V_28 ;
F_20 ( V_2 , V_24 , V_19 ) ;
F_20 ( V_2 , V_25 , V_19 ) ;
if ( V_26 ) {
F_19 ( V_2 , V_25 , V_2 -> V_30 ) ;
F_19 ( V_2 , V_24 , V_2 -> V_31 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_32 = V_2 -> V_33 & 0xffff ;
V_2 -> V_31 = V_2 -> V_34 & 0xffff ;
V_2 -> V_30 = V_2 -> V_35 & 0xffff ;
}
void F_24 ( struct V_1 * V_2 ,
unsigned int * V_36 ,
unsigned int V_37 )
{
unsigned int V_38 = V_2 -> V_34 ? V_2 -> V_34 : V_39 ;
unsigned int V_40 = V_2 -> V_35 ? V_2 -> V_35 : V_39 ;
unsigned int div = V_38 * V_40 ;
unsigned int V_41 = 0xffffffff ;
unsigned int V_42 = 0 ;
unsigned int V_43 = 0 ;
unsigned int V_44 = 0 ;
unsigned int V_45 = 0 ;
unsigned int V_46 = 0 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
if ( div * V_2 -> V_51 == * V_36 &&
V_38 > 1 && V_38 <= V_39 &&
V_40 > 1 && V_40 <= V_39 &&
div > V_38 && div > V_40 &&
div * V_2 -> V_51 > div &&
div * V_2 -> V_51 > V_2 -> V_51 )
return;
div = * V_36 / V_2 -> V_51 ;
V_40 = V_39 ;
V_47 = div / V_40 ;
if ( V_47 < 2 )
V_47 = 2 ;
for ( V_38 = V_47 ; V_38 <= div / V_38 + 1 && V_38 <= V_39 ; V_38 ++ ) {
for ( V_40 = div / V_38 ;
V_38 * V_40 <= div + V_38 + 1 && V_40 <= V_39 ; V_40 ++ ) {
V_48 = V_2 -> V_51 * V_38 * V_40 ;
if ( V_48 <= * V_36 && V_48 > V_42 ) {
V_42 = V_48 ;
V_44 = V_38 ;
V_46 = V_40 ;
}
if ( V_48 >= * V_36 && V_48 < V_41 ) {
V_41 = V_48 ;
V_43 = V_38 ;
V_45 = V_40 ;
}
}
}
switch ( V_37 & V_52 ) {
case V_53 :
default:
V_50 = V_43 * V_45 * V_2 -> V_51 ;
V_49 = V_44 * V_46 * V_2 -> V_51 ;
if ( V_50 - * V_36 < * V_36 - V_49 ) {
V_38 = V_43 ;
V_40 = V_45 ;
} else {
V_38 = V_44 ;
V_40 = V_46 ;
}
break;
case V_54 :
V_38 = V_43 ;
V_40 = V_45 ;
break;
case V_55 :
V_38 = V_44 ;
V_40 = V_46 ;
break;
}
* V_36 = V_38 * V_40 * V_2 -> V_51 ;
V_2 -> V_34 = V_38 ;
V_2 -> V_35 = V_40 ;
}
void F_25 ( struct V_1 * V_2 ,
unsigned int * V_36 , unsigned int V_37 )
{
unsigned int V_32 ;
switch ( V_37 & V_52 ) {
default:
case V_53 :
V_32 = F_26 ( * V_36 , V_2 -> V_51 ) ;
break;
case V_54 :
V_32 = F_27 ( * V_36 , V_2 -> V_51 ) ;
break;
case V_55 :
V_32 = * V_36 / V_2 -> V_51 ;
break;
}
if ( V_32 < 2 )
V_32 = 2 ;
if ( V_32 > V_39 )
V_32 = V_39 ;
* V_36 = V_32 * V_2 -> V_51 ;
V_2 -> V_33 = V_32 ;
}
void F_28 ( struct V_1 * V_2 ,
unsigned int V_13 , bool V_56 )
{
if ( V_13 < 3 )
V_2 -> V_56 [ V_13 ] = V_56 ;
}
static int F_29 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
unsigned int * V_63 )
{
struct V_1 * V_2 = V_60 -> V_64 ;
unsigned int V_65 = F_30 ( V_62 -> V_66 ) ;
int V_67 ;
if ( V_2 -> V_56 [ V_65 ] )
return - V_68 ;
for ( V_67 = 0 ; V_67 < V_62 -> V_69 ; V_67 ++ )
V_63 [ V_67 ] = F_17 ( V_2 , V_65 ) ;
return V_62 -> V_69 ;
}
static int F_31 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
unsigned int * V_63 )
{
struct V_1 * V_2 = V_60 -> V_64 ;
unsigned int V_65 = F_30 ( V_62 -> V_66 ) ;
if ( V_2 -> V_56 [ V_65 ] )
return - V_68 ;
if ( V_62 -> V_69 )
F_19 ( V_2 , V_65 , V_63 [ V_62 -> V_69 - 1 ] ) ;
return V_62 -> V_69 ;
}
static int F_32 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
unsigned int * V_63 )
{
struct V_1 * V_2 = V_60 -> V_64 ;
unsigned int V_65 = F_30 ( V_62 -> V_66 ) ;
int V_70 ;
if ( V_2 -> V_56 [ V_65 ] )
return - V_68 ;
switch ( V_63 [ 0 ] ) {
case V_71 :
V_70 = F_20 ( V_2 , V_65 ,
V_29 | V_28 ) ;
if ( V_70 )
return V_70 ;
break;
case V_72 :
V_70 = F_20 ( V_2 , V_65 , V_63 [ 1 ] ) ;
if ( V_70 )
return V_70 ;
break;
case V_73 :
V_63 [ 1 ] = F_15 ( V_2 , V_65 ) ;
break;
default:
if ( V_2 -> V_74 )
return V_2 -> V_74 ( V_58 , V_60 , V_62 , V_63 ) ;
return - V_20 ;
}
return V_62 -> V_69 ;
}
void F_33 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
V_60 -> type = V_75 ;
V_60 -> V_76 = V_77 | V_78 ;
V_60 -> V_79 = 3 ;
V_60 -> V_80 = 0xffff ;
V_60 -> V_81 = & V_82 ;
V_60 -> V_83 = F_29 ;
V_60 -> V_84 = F_31 ;
V_60 -> V_74 = F_32 ;
V_60 -> V_64 = V_2 ;
}
static struct V_1 * F_34 ( unsigned long V_10 ,
void T_1 * V_9 ,
unsigned int V_51 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_2 ;
int V_67 ;
if ( ! ( V_5 == V_8 || V_5 == V_11 ||
V_5 == V_12 ) )
return NULL ;
V_2 = F_35 ( sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_51 = V_51 ? V_51 : V_86 ;
for ( V_67 = 0 ; V_67 < 3 ; V_67 ++ )
F_20 ( V_2 , V_67 , V_29 | V_28 ) ;
return V_2 ;
}
struct V_1 * F_36 ( unsigned long V_10 ,
unsigned int V_51 ,
unsigned int V_5 ,
unsigned int V_6 )
{
return F_34 ( V_10 , NULL , V_51 , V_5 , V_6 ) ;
}
struct V_1 * F_37 ( void T_1 * V_9 ,
unsigned int V_51 ,
unsigned int V_5 ,
unsigned int V_6 )
{
return F_34 ( 0 , V_9 , V_51 , V_5 , V_6 ) ;
}
static int T_2 F_38 ( void )
{
return 0 ;
}
static void T_3 F_39 ( void )
{
}
