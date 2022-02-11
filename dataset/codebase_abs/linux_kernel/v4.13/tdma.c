bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
if ( ! V_4 -> V_6 )
return false ;
V_4 -> V_7 += V_5 ;
V_4 -> V_8 += V_5 ;
if ( V_4 -> V_8 == F_2 ( V_4 -> V_6 ) ) {
if ( F_3 ( V_4 -> V_6 ) )
return false ;
V_4 -> V_8 = 0 ;
V_4 -> V_6 = F_4 ( V_4 -> V_6 ) ;
}
if ( V_4 -> V_7 == V_2 -> V_9 )
return false ;
return true ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
F_6 ( 0 , V_13 -> V_14 + V_15 ) ;
F_7 ( V_13 , V_16 ) ;
F_6 ( V_17 | V_18 |
V_19 | V_20 ,
V_13 -> V_14 + V_21 ) ;
F_6 ( V_22 | V_23 |
V_24 | V_25 ,
V_13 -> V_14 + V_15 ) ;
F_6 ( V_11 -> V_26 . V_27 -> V_28 ,
V_13 -> V_14 + V_29 ) ;
F_8 ( F_9 ( V_13 -> V_14 + V_30 ) &
V_31 ) ;
F_10 ( V_31 , V_13 -> V_14 + V_30 ) ;
}
void F_11 ( struct V_10 * V_11 )
{
struct V_32 * V_33 ;
for ( V_33 = V_11 -> V_26 . V_27 ; V_33 ; ) {
struct V_32 * V_34 = V_33 ;
T_1 type = V_33 -> V_35 & V_36 ;
if ( type == V_37 )
F_12 ( V_38 -> V_39 -> V_40 , V_33 -> V_41 ,
F_13 ( V_33 -> V_42 ) ) ;
V_33 = V_33 -> V_43 ;
F_12 ( V_38 -> V_39 -> V_44 , V_34 ,
V_34 -> V_28 ) ;
}
V_11 -> V_26 . V_27 = NULL ;
V_11 -> V_26 . V_45 = NULL ;
}
void F_14 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_32 * V_33 ;
for ( V_33 = V_11 -> V_26 . V_27 ; V_33 ; V_33 = V_33 -> V_43 ) {
if ( V_33 -> V_35 & V_46 )
V_33 -> V_47 = F_15 ( V_33 -> V_47 + V_13 -> V_48 ) ;
if ( V_33 -> V_35 & V_49 )
V_33 -> V_42 = F_15 ( V_33 -> V_42 + V_13 -> V_48 ) ;
if ( ( V_33 -> V_35 & V_36 ) == V_37 )
F_16 ( V_13 , V_33 -> V_41 ) ;
}
}
void F_17 ( struct V_12 * V_13 ,
struct V_10 * V_11 )
{
if ( V_13 -> V_26 . V_27 == NULL && V_13 -> V_26 . V_45 == NULL ) {
V_13 -> V_26 . V_27 = V_11 -> V_26 . V_27 ;
V_13 -> V_26 . V_45 = V_11 -> V_26 . V_45 ;
} else {
struct V_32 * V_45 ;
V_45 = V_13 -> V_26 . V_45 ;
V_45 -> V_43 = V_11 -> V_26 . V_27 ;
V_13 -> V_26 . V_45 = V_11 -> V_26 . V_45 ;
if ( ! ( V_45 -> V_35 & V_50 ) &&
! ( V_11 -> V_26 . V_27 -> V_35 & V_51 ) )
V_45 -> V_52 = V_11 -> V_26 . V_27 -> V_28 ;
}
}
int F_18 ( struct V_12 * V_13 , T_1 V_53 )
{
struct V_54 * V_55 = NULL ;
struct V_32 * V_33 = NULL , * V_43 = NULL ;
T_2 V_56 ;
int V_57 = 0 ;
V_56 = F_9 ( V_13 -> V_14 + V_58 ) ;
for ( V_33 = V_13 -> V_26 . V_27 ; V_33 ; V_33 = V_43 ) {
F_19 ( & V_13 -> V_59 ) ;
V_43 = V_33 -> V_43 ;
F_20 ( & V_13 -> V_59 ) ;
if ( V_33 -> V_35 & V_60 ) {
struct V_54 * V_61 = NULL ;
struct V_62 * V_63 ;
T_1 V_64 ;
F_19 ( & V_13 -> V_59 ) ;
if ( ! V_55 )
V_55 = V_13 -> V_55 ;
else
V_55 = F_21 ( V_13 ,
& V_61 ) ;
V_13 -> V_26 . V_27 = V_33 -> V_43 ;
V_33 -> V_43 = NULL ;
if ( V_13 -> V_26 . V_27 == NULL )
V_13 -> V_26 . V_45 = NULL ;
F_20 ( & V_13 -> V_59 ) ;
V_63 = F_22 ( V_55 -> V_65 ) ;
V_64 = ( V_33 -> V_28 == V_56 ) ?
V_53 : V_16 ;
V_57 = V_63 -> V_66 -> V_67 ( V_55 , V_64 ) ;
V_63 -> V_66 -> V_68 ( V_55 ) ;
if ( V_57 == 0 )
F_23 ( V_13 ,
V_55 ) ;
if ( V_61 )
V_61 -> V_68 ( V_61 , - V_69 ) ;
}
if ( V_57 || V_33 -> V_28 == V_56 )
break;
}
if ( V_57 ) {
F_19 ( & V_13 -> V_59 ) ;
V_13 -> V_55 = V_55 ;
F_20 ( & V_13 -> V_59 ) ;
}
return V_57 ;
}
static struct V_32 *
F_24 ( struct F_17 * V_26 , T_3 V_35 )
{
struct V_32 * V_70 = NULL ;
T_2 V_71 ;
V_70 = F_25 ( V_38 -> V_39 -> V_44 , V_35 ,
& V_71 ) ;
if ( ! V_70 )
return F_26 ( - V_72 ) ;
V_70 -> V_28 = V_71 ;
if ( V_26 -> V_45 ) {
V_26 -> V_45 -> V_52 = F_15 ( V_71 ) ;
V_26 -> V_45 -> V_43 = V_70 ;
} else {
V_26 -> V_27 = V_70 ;
}
V_26 -> V_45 = V_70 ;
return V_70 ;
}
int F_27 ( struct F_17 * V_26 , T_2 V_42 ,
T_1 V_73 , T_1 V_35 , T_3 V_74 )
{
struct V_32 * V_33 , * V_75 ;
V_33 = F_24 ( V_26 , V_74 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
for ( V_75 = V_26 -> V_27 ; V_75 ; V_75 = V_75 -> V_43 ) {
T_1 type = V_75 -> V_35 & V_36 ;
if ( type == V_37 )
break;
}
if ( ! V_75 )
return - V_76 ;
V_33 -> V_77 = F_15 ( V_73 | F_30 ( 31 ) ) ;
V_33 -> V_42 = V_42 ;
V_33 -> V_47 = V_75 -> V_42 ;
V_33 -> V_41 = V_75 -> V_41 ;
V_35 &= ( V_46 | V_49 ) ;
V_33 -> V_35 = V_35 | V_78 ;
return 0 ;
}
struct V_79 * F_31 ( struct F_17 * V_26 ,
const struct V_79 * V_80 ,
bool V_81 ,
T_3 V_35 )
{
struct V_32 * V_33 ;
struct V_79 * V_41 ;
T_2 V_71 ;
unsigned int V_73 ;
V_33 = F_24 ( V_26 , V_35 ) ;
if ( F_28 ( V_33 ) )
return F_32 ( V_33 ) ;
V_41 = F_33 ( V_38 -> V_39 -> V_40 , V_35 , & V_71 ) ;
if ( ! V_41 )
return F_26 ( - V_72 ) ;
* V_41 = * V_80 ;
V_73 = V_81 ? sizeof( V_41 -> V_82 ) : sizeof( * V_41 ) ;
V_33 = V_26 -> V_45 ;
V_33 -> V_41 = V_41 ;
V_33 -> V_77 = F_15 ( V_73 | F_30 ( 31 ) ) ;
V_33 -> V_42 = F_15 ( V_71 ) ;
V_33 -> V_47 = V_83 ;
V_33 -> V_35 = V_46 | V_37 ;
return V_41 ;
}
int F_34 ( struct F_17 * V_26 ,
T_2 V_47 , T_2 V_42 , T_1 V_73 ,
T_1 V_35 , T_3 V_74 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( V_26 , V_74 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
V_33 -> V_77 = F_15 ( V_73 | F_30 ( 31 ) ) ;
V_33 -> V_42 = V_42 ;
V_33 -> V_47 = V_47 ;
V_35 &= ( V_46 | V_49 ) ;
V_33 -> V_35 = V_35 | V_84 ;
return 0 ;
}
int F_35 ( struct F_17 * V_26 , T_3 V_35 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( V_26 , V_35 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
return 0 ;
}
int F_36 ( struct F_17 * V_26 , T_3 V_35 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( V_26 , V_35 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
V_33 -> V_77 = F_15 ( F_30 ( 31 ) ) ;
return 0 ;
}
int F_37 ( struct F_17 * V_26 ,
struct V_1 * V_85 ,
struct V_3 * V_4 ,
T_3 V_74 )
{
T_1 V_35 = V_4 -> V_86 == V_87 ?
V_46 : V_49 ;
unsigned int V_5 ;
do {
T_2 V_47 , V_42 ;
int V_88 ;
V_5 = F_38 ( V_85 , V_4 ) ;
if ( V_4 -> V_86 == V_87 ) {
V_47 = V_89 + V_4 -> V_7 ;
V_42 = F_39 ( V_4 -> V_6 ) + V_4 -> V_8 ;
} else {
V_47 = F_39 ( V_4 -> V_6 ) + V_4 -> V_8 ;
V_42 = V_89 + V_4 -> V_7 ;
}
V_88 = F_34 ( V_26 , V_47 , V_42 , V_5 ,
V_35 , V_74 ) ;
if ( V_88 )
return V_88 ;
} while ( F_1 ( V_85 , V_4 , V_5 ) );
return 0 ;
}
