static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
int V_8 ;
if ( F_3 ( V_9 , & V_4 -> V_10 ) ) {
while ( ( V_7 = F_4 ( & V_4 -> V_11 ) ) ) {
if ( F_5 ( V_4 -> V_12 . V_13 . V_14 ) ) {
V_8 = V_4 -> V_12 . V_13 . V_15 ( V_4 -> V_12 . V_13 . V_14 , V_7 ) ;
if ( V_8 )
F_6 ( V_7 ) ;
} else
F_6 ( V_7 ) ;
}
}
if ( F_3 ( V_16 , & V_4 -> V_10 ) ) {
if ( V_4 -> V_17 )
V_4 -> V_17 ( V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_2 ( V_2 , struct V_18 , V_5 ) ;
struct V_6 * V_7 ;
int V_8 ;
if ( F_3 ( V_9 , & V_19 -> V_10 ) ) {
while ( ( V_7 = F_4 ( & V_19 -> V_11 ) ) ) {
V_19 -> V_20 -- ;
if ( F_5 ( V_19 -> V_21 . V_14 ) ) {
V_8 = V_19 -> V_21 . V_15 ( V_19 -> V_21 . V_14 , V_7 ) ;
if ( V_8 )
F_6 ( V_7 ) ;
} else
F_6 ( V_7 ) ;
}
}
}
int
F_8 ( struct V_3 * V_21 , int V_22 , void * V_23 )
{
F_9 ( V_24 , & V_21 -> V_10 ) ;
V_21 -> V_22 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_27 = NULL ;
V_21 -> V_28 = 0 ;
V_21 -> V_17 = V_23 ;
F_10 ( & V_21 -> V_29 ) ;
F_10 ( & V_21 -> V_11 ) ;
F_11 ( & V_21 -> V_12 . V_30 ) ;
F_12 ( & V_21 -> V_5 , F_1 ) ;
return 0 ;
}
int
F_13 ( struct V_18 * V_21 , unsigned short V_22 ,
unsigned short V_31 )
{
V_21 -> V_10 = 0 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_32 = V_31 ;
V_21 -> V_33 = V_31 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_34 = V_22 ;
V_21 -> V_35 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_27 = NULL ;
V_21 -> V_28 = 0 ;
F_10 ( & V_21 -> V_11 ) ;
V_21 -> V_20 = 0 ;
V_21 -> V_36 = NULL ;
F_12 ( & V_21 -> V_5 , F_7 ) ;
return 0 ;
}
int
F_14 ( struct V_3 * V_21 )
{
if ( V_21 -> V_27 ) {
F_6 ( V_21 -> V_27 ) ;
V_21 -> V_27 = NULL ;
}
if ( V_21 -> V_26 ) {
F_6 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
F_15 ( & V_21 -> V_29 ) ;
F_15 ( & V_21 -> V_11 ) ;
F_16 ( & V_21 -> V_5 ) ;
return 0 ;
}
void
F_17 ( struct V_18 * V_21 )
{
if ( V_21 -> V_27 ) {
F_6 ( V_21 -> V_27 ) ;
V_21 -> V_27 = NULL ;
}
V_21 -> V_28 = 0 ;
if ( V_21 -> V_26 ) {
F_6 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
if ( V_21 -> V_36 ) {
F_6 ( V_21 -> V_36 ) ;
V_21 -> V_36 = NULL ;
}
F_3 ( V_37 , & V_21 -> V_10 ) ;
F_3 ( V_38 , & V_21 -> V_10 ) ;
F_3 ( V_39 , & V_21 -> V_10 ) ;
F_3 ( V_40 , & V_21 -> V_10 ) ;
F_3 ( V_41 , & V_21 -> V_10 ) ;
F_3 ( V_42 , & V_21 -> V_10 ) ;
V_21 -> V_43 = 0 ;
V_21 -> V_31 = V_21 -> V_33 ;
V_21 -> V_32 = V_21 -> V_33 ;
V_21 -> V_22 = V_21 -> V_35 ;
V_21 -> V_34 = V_21 -> V_35 ;
}
int
F_18 ( struct V_18 * V_21 )
{
F_17 ( V_21 ) ;
F_15 ( & V_21 -> V_11 ) ;
V_21 -> V_20 = 0 ;
F_16 ( & V_21 -> V_5 ) ;
return 0 ;
}
int
F_19 ( struct V_18 * V_19 , struct V_44 * V_45 )
{
int V_46 = 0 ;
switch ( V_45 -> V_47 ) {
case V_48 :
V_45 -> V_47 = V_49 | V_50 |
V_51 ;
break;
case V_50 :
if ( V_45 -> V_52 ) {
memset ( V_19 -> V_53 , V_45 -> V_54 & 0xff , V_55 ) ;
F_9 ( V_40 , & V_19 -> V_10 ) ;
} else {
F_3 ( V_40 , & V_19 -> V_10 ) ;
}
break;
case V_51 :
V_45 -> V_54 = V_19 -> V_43 ;
if ( V_45 -> V_52 )
F_9 ( V_42 , & V_19 -> V_10 ) ;
else
F_3 ( V_42 , & V_19 -> V_10 ) ;
V_19 -> V_43 = 0 ;
break;
case V_49 :
if ( V_45 -> V_54 > V_56 )
V_19 -> V_34 = V_45 -> V_54 ;
if ( V_45 -> V_52 > V_56 )
V_19 -> V_32 = V_45 -> V_52 ;
V_45 -> V_52 = V_19 -> V_31 ;
V_45 -> V_54 = V_19 -> V_22 ;
break;
default:
F_20 ( L_1 , V_45 -> V_47 ) ;
V_46 = - V_57 ;
break;
}
return V_46 ;
}
static inline T_1
F_21 ( T_2 * V_58 )
{
T_1 V_59 , V_60 ;
V_59 = * V_58 >> 2 ;
V_60 = V_58 [ 1 ] >> 1 ;
return V_59 | ( V_60 << 8 ) ;
}
void
F_22 ( struct V_3 * V_4 )
{
struct V_61 * V_62 ;
if ( V_4 -> V_26 -> V_63 < 2 ) {
F_6 ( V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
return;
}
V_62 = F_23 ( V_4 -> V_26 ) ;
V_62 -> V_64 = V_65 ;
V_62 -> V_66 = F_21 ( V_4 -> V_26 -> V_67 ) ;
F_24 ( & V_4 -> V_11 , V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
F_25 ( V_4 , V_9 ) ;
}
void
F_26 ( struct V_3 * V_68 , struct V_3 * V_4 )
{
struct V_61 * V_62 ;
if ( V_68 -> V_26 -> V_63 < 2 ) {
F_6 ( V_68 -> V_26 ) ;
V_68 -> V_26 = NULL ;
return;
}
V_62 = F_23 ( V_68 -> V_26 ) ;
V_62 -> V_64 = V_69 ;
V_62 -> V_66 = F_21 ( V_68 -> V_26 -> V_67 ) ;
F_24 ( & V_4 -> V_11 , V_68 -> V_26 ) ;
V_68 -> V_26 = NULL ;
F_25 ( V_4 , V_9 ) ;
}
void
F_27 ( struct V_18 * V_19 , unsigned int V_66 , bool V_70 )
{
struct V_61 * V_62 ;
if ( F_28 ( ! V_19 -> V_26 ) )
return;
if ( F_28 ( ! V_19 -> V_26 -> V_63 ) ) {
F_6 ( V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
} else {
if ( F_29 ( V_71 , & V_19 -> V_10 ) &&
( V_19 -> V_26 -> V_63 < V_19 -> V_31 ) && ! V_70 )
return;
V_62 = F_23 ( V_19 -> V_26 ) ;
V_62 -> V_64 = V_65 ;
V_62 -> V_66 = V_66 ;
if ( V_19 -> V_20 >= 64 ) {
F_30 ( V_72
L_2 ,
V_19 -> V_73 ) ;
F_15 ( & V_19 -> V_11 ) ;
}
V_19 -> V_20 ++ ;
F_24 ( & V_19 -> V_11 , V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
F_25 ( V_19 , V_9 ) ;
}
}
void
F_31 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_24 ( & V_4 -> V_11 , V_7 ) ;
F_25 ( V_4 , V_9 ) ;
}
void
F_32 ( struct V_18 * V_19 , struct V_6 * V_7 )
{
if ( V_19 -> V_20 >= 64 ) {
F_30 ( V_72 L_3
L_4 , V_19 ) ;
F_15 ( & V_19 -> V_11 ) ;
V_19 -> V_20 = 0 ;
}
V_19 -> V_20 ++ ;
F_24 ( & V_19 -> V_11 , V_7 ) ;
F_25 ( V_19 , V_9 ) ;
}
static void
F_33 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = F_34 ( V_74 , F_35 ( V_4 -> V_27 ) ,
0 , NULL , V_75 ) ;
if ( ! V_7 ) {
F_30 ( V_76 L_5 , V_77 ,
F_35 ( V_4 -> V_27 ) ) ;
return;
}
F_24 ( & V_4 -> V_11 , V_7 ) ;
F_25 ( V_4 , V_9 ) ;
}
int
F_36 ( struct V_3 * V_4 )
{
V_4 -> V_28 = 0 ;
V_4 -> V_27 = F_4 ( & V_4 -> V_29 ) ;
if ( V_4 -> V_27 ) {
F_33 ( V_4 ) ;
return 1 ;
}
V_4 -> V_27 = NULL ;
F_3 ( V_37 , & V_4 -> V_10 ) ;
return 0 ;
}
static void
F_37 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
if ( V_19 -> V_20 >= 64 ) {
F_30 ( V_72 L_3
L_4 , V_19 ) ;
F_15 ( & V_19 -> V_11 ) ;
V_19 -> V_20 = 0 ;
}
V_7 = F_34 ( V_74 , F_35 ( V_19 -> V_27 ) ,
0 , NULL , V_75 ) ;
if ( ! V_7 ) {
F_30 ( V_76 L_5 , V_77 ,
F_35 ( V_19 -> V_27 ) ) ;
return;
}
V_19 -> V_20 ++ ;
F_24 ( & V_19 -> V_11 , V_7 ) ;
F_25 ( V_19 , V_9 ) ;
}
int
F_38 ( struct V_18 * V_19 )
{
V_19 -> V_28 = 0 ;
if ( F_29 ( V_38 , & V_19 -> V_10 ) ) {
V_19 -> V_27 = V_19 -> V_36 ;
if ( V_19 -> V_27 ) {
V_19 -> V_36 = NULL ;
F_3 ( V_38 , & V_19 -> V_10 ) ;
F_37 ( V_19 ) ;
return 1 ;
} else {
F_3 ( V_38 , & V_19 -> V_10 ) ;
F_30 ( V_72 L_6 ) ;
}
}
V_19 -> V_27 = NULL ;
F_3 ( V_37 , & V_19 -> V_10 ) ;
return 0 ;
}
void
F_39 ( struct V_78 * V_21 , T_1 V_79 , int V_66 , struct V_6 * V_7 )
{
struct V_61 * V_62 ;
if ( ! V_7 ) {
F_40 ( V_21 , V_79 , V_66 , 0 , NULL , V_75 ) ;
} else {
if ( V_21 -> V_14 ) {
V_62 = F_23 ( V_7 ) ;
V_62 -> V_64 = V_79 ;
V_62 -> V_66 = V_66 ;
if ( ! V_21 -> V_15 ( V_21 -> V_14 , V_7 ) )
return;
}
F_6 ( V_7 ) ;
}
}
int
F_41 ( struct V_3 * V_21 , struct V_6 * V_7 )
{
if ( V_7 -> V_63 <= 0 ) {
F_30 ( V_72 L_7 , V_77 ) ;
return - V_57 ;
}
if ( V_7 -> V_63 > V_21 -> V_22 ) {
F_30 ( V_72 L_8 ,
V_77 , V_7 -> V_63 , V_21 -> V_22 ) ;
return - V_57 ;
}
if ( F_9 ( V_37 , & V_21 -> V_10 ) ) {
F_24 ( & V_21 -> V_29 , V_7 ) ;
return 0 ;
} else {
V_21 -> V_27 = V_7 ;
V_21 -> V_28 = 0 ;
return 1 ;
}
}
int
F_42 ( struct V_18 * V_21 , struct V_6 * V_7 )
{
if ( V_7 -> V_63 <= 0 ) {
F_30 ( V_72 L_7 , V_77 ) ;
return - V_57 ;
}
if ( V_7 -> V_63 > V_21 -> V_22 ) {
F_30 ( V_72 L_8 ,
V_77 , V_7 -> V_63 , V_21 -> V_22 ) ;
return - V_57 ;
}
if ( V_21 -> V_36 ) {
F_30 ( V_72
L_9 ,
V_77 , V_7 -> V_63 , V_21 -> V_36 -> V_63 ) ;
return - V_80 ;
}
if ( F_9 ( V_37 , & V_21 -> V_10 ) ) {
F_9 ( V_38 , & V_21 -> V_10 ) ;
V_21 -> V_36 = V_7 ;
return 0 ;
} else {
V_21 -> V_27 = V_7 ;
V_21 -> V_28 = 0 ;
F_37 ( V_21 ) ;
return 1 ;
}
}
int
F_43 ( struct V_18 * V_19 , int V_81 )
{
int V_63 ;
if ( V_19 -> V_26 ) {
V_63 = F_44 ( V_19 -> V_26 ) ;
if ( V_63 < V_81 ) {
F_45 ( L_10 ,
V_19 -> V_73 , V_81 , V_63 ) ;
if ( F_29 ( V_71 , & V_19 -> V_10 ) ) {
F_27 ( V_19 , 0 , true ) ;
} else {
return - V_82 ;
}
} else {
return V_63 ;
}
}
if ( F_28 ( V_19 -> V_22 != V_19 -> V_34 ) )
V_19 -> V_22 = V_19 -> V_34 ;
if ( F_28 ( V_19 -> V_31 != V_19 -> V_32 ) )
V_19 -> V_31 = V_19 -> V_32 ;
if ( F_28 ( V_81 > V_19 -> V_22 ) )
return - V_82 ;
if ( F_29 ( V_71 , & V_19 -> V_10 ) ) {
if ( V_81 >= V_19 -> V_31 ) {
V_63 = V_81 ;
} else {
V_63 = 2 * V_19 -> V_31 ;
if ( V_63 > V_19 -> V_22 )
V_63 = V_19 -> V_22 ;
}
} else {
V_63 = V_19 -> V_22 ;
}
V_19 -> V_26 = F_46 ( V_63 , V_75 ) ;
if ( ! V_19 -> V_26 ) {
F_45 ( L_11 ,
V_19 -> V_73 , V_63 ) ;
V_63 = - V_83 ;
}
return V_63 ;
}
