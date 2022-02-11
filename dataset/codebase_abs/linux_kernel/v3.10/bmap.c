struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 -> V_8 ;
return V_5 -> V_9 ;
}
static int F_2 ( struct V_2 * V_3 ,
const char * V_10 , int V_11 )
{
struct V_1 * V_1 = V_3 -> V_6 ;
if ( V_11 == - V_12 ) {
F_3 ( V_1 -> V_7 , V_10 ,
L_1 , V_1 -> V_13 ) ;
V_11 = - V_14 ;
}
return V_11 ;
}
int F_4 ( struct V_2 * V_3 , T_1 V_15 , int V_16 ,
T_1 * V_17 )
{
T_2 V_18 ;
int V_19 ;
F_5 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_22 ( V_3 , V_15 , V_16 , V_17 ) ;
if ( V_19 < 0 ) {
V_19 = F_2 ( V_3 , V_23 , V_19 ) ;
goto V_24;
}
if ( F_6 ( V_3 ) ) {
V_19 = F_7 ( F_1 ( V_3 ) , * V_17 ,
& V_18 ) ;
if ( ! V_19 )
* V_17 = V_18 ;
}
V_24:
F_8 ( & V_3 -> V_20 ) ;
return V_19 ;
}
int F_9 ( struct V_2 * V_3 , T_1 V_15 , T_1 * V_17 ,
unsigned V_25 )
{
int V_19 ;
F_5 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_26 ( V_3 , V_15 , V_17 , V_25 ) ;
F_8 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_15 , T_1 V_27 )
{
T_1 V_28 [ V_29 + 1 ] ;
T_1 V_30 [ V_29 + 1 ] ;
int V_19 , V_31 ;
if ( V_3 -> V_21 -> V_32 != NULL ) {
V_19 = V_3 -> V_21 -> V_32 ( V_3 , V_15 ) ;
if ( V_19 > 0 ) {
V_31 = V_3 -> V_21 -> V_33 (
V_3 , V_28 , V_30 , V_29 + 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_19 = F_11 (
V_3 , V_15 , V_27 , V_28 , V_30 , V_31 ) ;
if ( V_19 == 0 )
V_3 -> V_34 . V_35 |= V_36 ;
return V_19 ;
} else if ( V_19 < 0 )
return V_19 ;
}
return V_3 -> V_21 -> V_37 ( V_3 , V_15 , V_27 ) ;
}
int F_12 ( struct V_2 * V_3 ,
unsigned long V_15 ,
unsigned long V_38 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = F_10 ( V_3 , V_15 , V_38 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
static int F_15 ( struct V_2 * V_3 , T_1 V_15 )
{
T_1 V_28 [ V_39 + 1 ] ;
T_1 V_30 [ V_39 + 1 ] ;
int V_19 , V_31 ;
if ( V_3 -> V_21 -> V_40 != NULL ) {
V_19 = V_3 -> V_21 -> V_40 ( V_3 , V_15 ) ;
if ( V_19 > 0 ) {
V_31 = V_3 -> V_21 -> V_33 (
V_3 , V_28 , V_30 , V_39 + 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_19 = F_16 (
V_3 , V_15 , V_28 , V_30 , V_31 ) ;
if ( V_19 == 0 )
V_3 -> V_34 . V_35 &= ~ V_36 ;
return V_19 ;
} else if ( V_19 < 0 )
return V_19 ;
}
return V_3 -> V_21 -> V_41 ( V_3 , V_15 ) ;
}
int F_17 ( struct V_2 * V_3 , unsigned long * V_15 )
{
T_1 V_42 ;
int V_19 ;
F_5 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_43 ( V_3 , & V_42 ) ;
F_8 ( & V_3 -> V_20 ) ;
if ( V_19 < 0 )
V_19 = F_2 ( V_3 , V_23 , V_19 ) ;
else
* V_15 = V_42 ;
return V_19 ;
}
int F_18 ( struct V_2 * V_3 , unsigned long V_15 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = F_15 ( V_3 , V_15 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
static int F_19 ( struct V_2 * V_3 , unsigned long V_15 )
{
T_1 V_42 ;
int V_19 ;
V_19 = V_3 -> V_21 -> V_43 ( V_3 , & V_42 ) ;
if ( V_19 < 0 ) {
if ( V_19 == - V_44 )
V_19 = 0 ;
return V_19 ;
}
while ( V_15 <= V_42 ) {
V_19 = F_15 ( V_3 , V_42 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = V_3 -> V_21 -> V_43 ( V_3 , & V_42 ) ;
if ( V_19 < 0 ) {
if ( V_19 == - V_44 )
V_19 = 0 ;
return V_19 ;
}
}
return 0 ;
}
int F_20 ( struct V_2 * V_3 , unsigned long V_15 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = F_19 ( V_3 , V_15 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
F_13 ( & V_3 -> V_20 ) ;
if ( V_3 -> V_21 -> V_45 != NULL )
V_3 -> V_21 -> V_45 ( V_3 ) ;
F_14 ( & V_3 -> V_20 ) ;
}
int F_22 ( struct V_2 * V_3 , struct V_46 * V_47 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_48 ( V_3 , V_47 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
void F_23 ( struct V_2 * V_3 ,
struct V_49 * V_50 )
{
if ( V_3 -> V_21 -> V_51 != NULL )
V_3 -> V_21 -> V_51 ( V_3 , V_50 ) ;
}
int F_24 ( struct V_2 * V_3 ,
struct V_46 * * V_47 ,
unsigned long V_18 ,
union V_52 * V_53 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_54 ( V_3 , V_47 , V_18 , V_53 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
int F_25 ( struct V_2 * V_3 , T_1 V_15 , int V_16 )
{
int V_19 ;
if ( V_3 -> V_21 -> V_55 == NULL )
return 0 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = V_3 -> V_21 -> V_55 ( V_3 , V_15 , V_16 ) ;
F_14 ( & V_3 -> V_20 ) ;
return F_2 ( V_3 , V_23 , V_19 ) ;
}
int F_26 ( struct V_2 * V_3 )
{
int V_19 ;
F_13 ( & V_3 -> V_20 ) ;
V_19 = F_27 ( V_3 ) ;
F_28 ( V_3 ) ;
F_14 ( & V_3 -> V_20 ) ;
return V_19 ;
}
T_1 F_29 ( const struct V_2 * V_3 ,
const struct V_46 * V_47 )
{
struct V_46 * V_56 ;
T_1 V_15 ;
V_15 = F_30 ( V_47 -> V_57 ) << ( V_58 -
V_3 -> V_6 -> V_59 ) ;
for ( V_56 = F_31 ( V_47 -> V_57 ) ; V_56 != V_47 ; V_56 = V_56 -> V_60 )
V_15 ++ ;
return V_15 ;
}
T_1 F_32 ( const struct V_2 * V_3 , T_1 V_15 )
{
T_3 V_61 ;
V_61 = V_15 - V_3 -> V_62 ;
if ( ( F_33 ( V_61 ) < V_63 ) &&
( V_3 -> V_64 != V_65 ) &&
( V_3 -> V_64 + V_61 > 0 ) )
return V_3 -> V_64 + V_61 ;
else
return V_65 ;
}
T_1 F_34 ( const struct V_2 * V_3 )
{
struct V_1 * V_66 = F_1 ( V_3 ) ;
unsigned long V_67 = F_35 ( V_66 ) ;
unsigned long V_68 = V_3 -> V_6 -> V_13 / V_67 ;
return V_68 * V_67 +
( V_3 -> V_6 -> V_13 % V_69 ) *
( V_67 / V_69 ) ;
}
int F_36 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
if ( V_71 == NULL )
memset ( V_3 -> V_34 . V_72 , 0 , V_73 ) ;
else
memcpy ( V_3 -> V_34 . V_72 , V_71 -> V_74 , V_73 ) ;
F_37 ( & V_3 -> V_20 ) ;
V_3 -> V_75 = 0 ;
V_3 -> V_6 = & F_38 ( V_3 ) -> V_76 ;
switch ( V_3 -> V_6 -> V_13 ) {
case V_77 :
V_3 -> V_78 = V_79 ;
V_3 -> V_62 = 0 ;
V_3 -> V_64 = V_80 ;
F_39 ( & V_3 -> V_20 , & V_81 ) ;
break;
case V_82 :
case V_83 :
V_3 -> V_78 = V_84 ;
V_3 -> V_62 = 0 ;
V_3 -> V_64 = V_65 ;
F_39 ( & V_3 -> V_20 , & V_85 ) ;
break;
case V_86 :
F_39 ( & V_3 -> V_20 , & V_85 ) ;
default:
V_3 -> V_78 = V_87 ;
V_3 -> V_62 = 0 ;
V_3 -> V_64 = V_65 ;
break;
}
return ( V_3 -> V_34 . V_35 & V_36 ) ?
F_40 ( V_3 ) : F_41 ( V_3 ) ;
}
void F_42 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
F_13 ( & V_3 -> V_20 ) ;
memcpy ( V_71 -> V_74 , V_3 -> V_34 . V_72 ,
V_63 * sizeof( V_88 ) ) ;
if ( V_3 -> V_6 -> V_13 == V_77 )
V_3 -> V_64 = V_80 ;
F_14 ( & V_3 -> V_20 ) ;
}
void F_43 ( struct V_2 * V_3 )
{
memset ( & V_3 -> V_34 , 0 , V_73 ) ;
F_37 ( & V_3 -> V_20 ) ;
V_3 -> V_6 = & F_38 ( V_3 ) -> V_76 ;
V_3 -> V_78 = V_89 ;
V_3 -> V_62 = 0 ;
V_3 -> V_64 = V_65 ;
V_3 -> V_75 = 0 ;
F_44 ( V_3 ) ;
}
void F_45 ( const struct V_2 * V_3 ,
struct V_90 * V_91 )
{
memcpy ( V_91 -> V_92 , V_3 -> V_34 . V_72 , sizeof( V_91 -> V_92 ) ) ;
V_91 -> V_93 = V_3 -> V_62 ;
V_91 -> V_94 = V_3 -> V_64 ;
V_91 -> V_95 = V_3 -> V_75 ;
}
void F_46 ( struct V_2 * V_3 ,
const struct V_90 * V_91 )
{
memcpy ( V_3 -> V_34 . V_72 , V_91 -> V_92 , sizeof( V_91 -> V_92 ) ) ;
V_3 -> V_62 = V_91 -> V_93 ;
V_3 -> V_64 = V_91 -> V_94 ;
V_3 -> V_75 = V_91 -> V_95 ;
}
