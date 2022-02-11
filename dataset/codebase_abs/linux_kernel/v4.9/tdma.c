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
else if ( type == V_43 )
F_12 ( V_38 -> V_39 -> V_44 , V_33 -> V_45 ,
F_13 ( V_33 -> V_46 ) ) ;
V_33 = V_33 -> V_47 ;
F_12 ( V_38 -> V_39 -> V_48 , V_34 ,
V_34 -> V_28 ) ;
}
V_11 -> V_26 . V_27 = NULL ;
V_11 -> V_26 . V_49 = NULL ;
}
void F_14 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_32 * V_33 ;
for ( V_33 = V_11 -> V_26 . V_27 ; V_33 ; V_33 = V_33 -> V_47 ) {
if ( V_33 -> V_35 & V_50 )
V_33 -> V_46 = F_15 ( V_33 -> V_46 + V_13 -> V_51 ) ;
if ( V_33 -> V_35 & V_52 )
V_33 -> V_42 = F_15 ( V_33 -> V_42 + V_13 -> V_51 ) ;
if ( ( V_33 -> V_35 & V_36 ) == V_37 )
F_16 ( V_13 , V_33 -> V_41 ) ;
}
}
void F_17 ( struct V_12 * V_13 ,
struct V_10 * V_11 )
{
if ( V_13 -> V_26 . V_27 == NULL && V_13 -> V_26 . V_49 == NULL ) {
V_13 -> V_26 . V_27 = V_11 -> V_26 . V_27 ;
V_13 -> V_26 . V_49 = V_11 -> V_26 . V_49 ;
} else {
struct V_32 * V_49 ;
V_49 = V_13 -> V_26 . V_49 ;
V_49 -> V_47 = V_11 -> V_26 . V_27 ;
V_13 -> V_26 . V_49 = V_11 -> V_26 . V_49 ;
if ( ! ( V_49 -> V_35 & V_53 ) )
V_49 -> V_54 = V_11 -> V_26 . V_27 -> V_28 ;
}
}
int F_18 ( struct V_12 * V_13 , T_1 V_55 )
{
struct V_56 * V_57 = NULL ;
struct V_32 * V_33 = NULL , * V_47 = NULL ;
T_2 V_58 ;
int V_59 = 0 ;
V_58 = F_9 ( V_13 -> V_14 + V_60 ) ;
for ( V_33 = V_13 -> V_26 . V_27 ; V_33 ; V_33 = V_47 ) {
F_19 ( & V_13 -> V_61 ) ;
V_47 = V_33 -> V_47 ;
F_20 ( & V_13 -> V_61 ) ;
if ( V_33 -> V_35 & V_62 ) {
struct V_56 * V_63 = NULL ;
struct V_64 * V_65 ;
T_1 V_66 ;
F_19 ( & V_13 -> V_61 ) ;
if ( ! V_57 )
V_57 = V_13 -> V_57 ;
else
V_57 = F_21 ( V_13 ,
& V_63 ) ;
V_13 -> V_26 . V_27 = V_33 -> V_47 ;
V_33 -> V_47 = NULL ;
if ( V_13 -> V_26 . V_27 == NULL )
V_13 -> V_26 . V_49 = NULL ;
F_20 ( & V_13 -> V_61 ) ;
V_65 = F_22 ( V_57 -> V_67 ) ;
V_66 = ( V_33 -> V_28 == V_58 ) ?
V_55 : V_16 ;
V_59 = V_65 -> V_68 -> V_69 ( V_57 , V_66 ) ;
V_65 -> V_68 -> V_70 ( V_57 ) ;
if ( V_59 == 0 )
F_23 ( V_13 ,
V_57 ) ;
if ( V_63 )
V_63 -> V_70 ( V_63 , - V_71 ) ;
}
if ( V_59 || V_33 -> V_28 == V_58 )
break;
}
if ( V_59 ) {
F_19 ( & V_13 -> V_61 ) ;
V_13 -> V_57 = V_57 ;
F_20 ( & V_13 -> V_61 ) ;
}
return V_59 ;
}
static struct V_32 *
F_24 ( struct F_17 * V_26 , T_3 V_35 )
{
struct V_32 * V_72 = NULL ;
T_2 V_73 ;
V_72 = F_25 ( V_38 -> V_39 -> V_48 , V_35 ,
& V_73 ) ;
if ( ! V_72 )
return F_26 ( - V_74 ) ;
V_72 -> V_28 = V_73 ;
if ( V_26 -> V_49 ) {
V_26 -> V_49 -> V_54 = F_15 ( V_73 ) ;
V_26 -> V_49 -> V_47 = V_72 ;
} else {
V_26 -> V_27 = V_72 ;
}
V_26 -> V_49 = V_72 ;
return V_72 ;
}
int F_27 ( struct F_17 * V_26 , T_2 V_42 ,
T_1 V_75 , T_1 V_35 , T_3 V_76 )
{
struct V_32 * V_33 ;
T_4 * V_77 ;
T_2 V_73 ;
V_33 = F_24 ( V_26 , V_76 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
V_77 = F_30 ( V_38 -> V_39 -> V_44 , V_76 , & V_73 ) ;
if ( ! V_77 )
return - V_74 ;
V_33 -> V_78 = F_15 ( V_75 | F_31 ( 31 ) ) ;
V_33 -> V_42 = V_42 ;
V_33 -> V_46 = F_15 ( V_73 ) ;
V_33 -> V_45 = V_77 ;
V_35 &= ( V_50 | V_52 ) ;
V_33 -> V_35 = V_35 | V_43 ;
return 0 ;
}
struct V_79 * F_32 ( struct F_17 * V_26 ,
const struct V_79 * V_80 ,
bool V_81 ,
T_3 V_35 )
{
struct V_32 * V_33 ;
struct V_79 * V_41 ;
T_2 V_73 ;
unsigned int V_75 ;
V_33 = F_24 ( V_26 , V_35 ) ;
if ( F_28 ( V_33 ) )
return F_33 ( V_33 ) ;
V_41 = F_30 ( V_38 -> V_39 -> V_40 , V_35 , & V_73 ) ;
if ( ! V_41 )
return F_26 ( - V_74 ) ;
* V_41 = * V_80 ;
V_75 = V_81 ? sizeof( V_41 -> V_82 ) : sizeof( * V_41 ) ;
V_33 = V_26 -> V_49 ;
V_33 -> V_41 = V_41 ;
V_33 -> V_78 = F_15 ( V_75 | F_31 ( 31 ) ) ;
V_33 -> V_42 = F_15 ( V_73 ) ;
V_33 -> V_46 = V_83 ;
V_33 -> V_35 = V_50 | V_37 ;
return V_41 ;
}
int F_34 ( struct F_17 * V_26 ,
T_2 V_46 , T_2 V_42 , T_1 V_75 ,
T_1 V_35 , T_3 V_76 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( V_26 , V_76 ) ;
if ( F_28 ( V_33 ) )
return F_29 ( V_33 ) ;
V_33 -> V_78 = F_15 ( V_75 | F_31 ( 31 ) ) ;
V_33 -> V_42 = V_42 ;
V_33 -> V_46 = V_46 ;
V_35 &= ( V_50 | V_52 ) ;
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
V_33 -> V_78 = F_15 ( F_31 ( 31 ) ) ;
return 0 ;
}
int F_37 ( struct F_17 * V_26 ,
struct V_1 * V_85 ,
struct V_3 * V_4 ,
T_3 V_76 )
{
T_1 V_35 = V_4 -> V_86 == V_87 ?
V_50 : V_52 ;
unsigned int V_5 ;
do {
T_2 V_46 , V_42 ;
int V_88 ;
V_5 = F_38 ( V_85 , V_4 ) ;
if ( V_4 -> V_86 == V_87 ) {
V_46 = V_89 + V_4 -> V_7 ;
V_42 = F_39 ( V_4 -> V_6 ) + V_4 -> V_8 ;
} else {
V_46 = F_39 ( V_4 -> V_6 ) + V_4 -> V_8 ;
V_42 = V_89 + V_4 -> V_7 ;
}
V_88 = F_34 ( V_26 , V_46 , V_42 , V_5 ,
V_35 , V_76 ) ;
if ( V_88 )
return V_88 ;
} while ( F_1 ( V_85 , V_4 , V_5 ) );
return 0 ;
}
