static enum V_1 F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 , int * V_11 ,
int V_12 )
{
enum V_1 V_13 ;
int V_14 = 0 ;
int V_15 ;
T_1 V_16 ;
F_2 ( 0 , L_1 , V_12 ,
V_10 & V_17 ) ;
if ( V_12 )
F_3 ( V_5 -> V_16 != V_3 -> V_18 ) ;
else
F_3 ( V_5 -> V_16 == V_3 -> V_18 ) ;
F_4 ( & V_3 -> V_19 ) ;
V_15 = ! F_5 ( & V_7 -> V_20 ) ;
F_6 ( & V_3 -> V_19 ) ;
if ( V_15 && ! ( V_10 & V_21 ) ) {
F_2 ( V_22 , L_2
L_3 , V_5 -> V_23 . V_24 ,
V_5 -> V_23 . V_25 ) ;
return V_26 ;
}
F_4 ( & V_5 -> V_27 ) ;
if ( V_5 -> V_28 & V_29 ) {
if ( V_12 && ! ( V_10 & V_21 ) ) {
F_2 ( V_22 , L_4 ) ;
F_6 ( & V_5 -> V_27 ) ;
return V_30 ;
}
F_7 ( V_5 ) ;
V_5 -> V_28 |= V_29 ;
}
F_4 ( & V_7 -> V_27 ) ;
if ( V_5 -> V_28 & V_31 ) {
V_13 = V_32 ;
goto V_33;
}
if ( V_5 -> V_28 & V_34 ) {
V_13 = V_35 ;
goto V_33;
}
if ( V_10 & V_21 )
V_13 = F_8 ( V_3 , V_5 , V_7 , V_9 , & V_14 ) ;
else
V_13 = F_9 ( V_3 , V_5 , V_7 , V_9 , & V_14 ) ;
if ( V_13 != V_36 && ( V_13 != V_37 || ! V_12 ) )
goto V_33;
if ( V_10 & V_17 ) {
if ( V_12 )
memcpy ( V_5 -> V_38 , V_9 -> V_38 , V_39 ) ;
else
V_10 |= V_40 ;
}
if ( ! V_12 ) {
V_16 = V_5 -> V_16 ;
if ( V_10 & V_21 )
V_7 -> V_41 = 1 ;
else
V_7 -> V_42 = 1 ;
F_6 ( & V_7 -> V_27 ) ;
F_6 ( & V_5 -> V_27 ) ;
V_13 = F_10 ( V_3 , V_5 , V_7 , V_9 ,
V_10 , V_16 ) ;
F_4 ( & V_5 -> V_27 ) ;
F_4 ( & V_7 -> V_27 ) ;
if ( V_13 == V_37 ) {
V_14 &= ~ ( V_43 |
V_44 |
V_45 ) ;
} else if ( V_13 == V_32 ||
V_13 == V_35 ||
V_13 == V_30 ||
V_13 == V_46
) {
F_2 ( 0 , L_5 ,
V_3 -> V_25 , V_5 -> V_23 . V_24 ,
V_5 -> V_23 . V_25 ,
V_13 == V_32 ? L_6 :
( V_13 == V_35 ? L_7 :
( V_13 == V_30 ? L_8 :
L_9 ) ) ) ;
V_14 = 0 ;
}
if ( V_10 & V_21 )
V_7 -> V_41 = 0 ;
else
V_7 -> V_42 = 0 ;
}
F_11 ( V_7 ) ;
if ( V_14 & V_43 ) {
F_12 ( & V_7 -> V_47 ) ;
F_13 ( V_7 ) ;
}
if ( V_14 & V_44 ) {
F_11 ( V_7 ) ;
F_14 ( & V_7 -> V_47 , & V_5 -> V_48 ) ;
}
if ( V_14 & V_45 ) {
F_2 ( 0 , L_10 ,
V_12 ? L_11 : L_12 ) ;
V_7 -> V_49 . V_50 = V_51 ;
}
F_13 ( V_7 ) ;
V_33:
V_5 -> V_28 &= ~ V_29 ;
if ( ! F_15 ( & V_5 -> V_52 , V_7 ) )
F_3 ( V_7 -> V_49 . V_50 != V_51 ) ;
else
F_3 ( V_7 -> V_49 . V_50 == V_51 ) ;
F_6 ( & V_7 -> V_27 ) ;
F_6 ( & V_5 -> V_27 ) ;
F_16 ( & V_5 -> V_53 ) ;
if ( V_14 & V_54 ) {
F_3 ( ! ( V_14 & V_43 ) ) ;
F_2 ( 0 , L_13 ,
F_17 ( F_18 ( V_7 -> V_49 . V_55 ) ) ,
F_19 ( F_18 ( V_7 -> V_49 . V_55 ) ) ,
F_20 ( & V_7 -> V_56 ) - 1 ) ;
F_13 ( V_7 ) ;
}
if ( V_14 & V_57 )
* V_11 = 1 ;
if ( V_13 == V_36 )
V_9 -> V_10 &= ~ ( V_58 | V_59 ) ;
return V_13 ;
}
void F_21 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_47 ) ;
}
void F_22 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_23 ( & V_7 -> V_47 , & V_5 -> V_48 ) ;
V_7 -> V_49 . V_50 = V_51 ;
}
static inline enum V_1 F_24 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 ,
int * V_11 )
{
return F_1 ( V_3 , V_5 , V_7 , V_9 , V_10 , V_11 , 1 ) ;
}
static inline enum V_1 F_25 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 , int * V_11 )
{
return F_1 ( V_3 , V_5 , V_7 , V_9 , V_10 , V_11 , 0 ) ;
}
static enum V_1 F_10 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 ,
T_1 V_16 )
{
struct V_60 V_61 ;
int V_62 ;
enum V_1 V_63 ;
int V_13 = 0 ;
struct V_64 V_65 [ 2 ] ;
T_2 V_66 = 1 ;
F_2 ( 0 , L_14 , V_5 -> V_23 . V_24 , V_5 -> V_23 . V_25 ) ;
if ( V_16 == V_3 -> V_18 ) {
F_2 ( 0 , L_15
L_16 , V_3 -> V_25 ,
V_5 -> V_23 . V_24 , V_5 -> V_23 . V_25 ) ;
return V_30 ;
}
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_67 = V_3 -> V_18 ;
V_61 . V_10 = F_26 ( V_10 ) ;
V_61 . V_55 = V_7 -> V_49 . V_55 ;
V_61 . V_68 = V_5 -> V_23 . V_24 ;
memcpy ( V_61 . V_25 , V_5 -> V_23 . V_25 , V_61 . V_68 ) ;
V_65 [ 0 ] . V_69 = sizeof( struct V_60 ) ;
V_65 [ 0 ] . V_70 = & V_61 ;
if ( V_10 & V_40 ) {
V_65 [ 1 ] . V_69 = V_39 ;
V_65 [ 1 ] . V_70 = V_7 -> V_9 -> V_38 ;
V_66 ++ ;
}
V_62 = F_27 ( V_71 , V_3 -> V_72 ,
V_65 , V_66 , V_16 , & V_13 ) ;
if ( V_62 >= 0 ) {
if ( V_13 == V_30 )
F_2 ( 0 , L_17 ) ;
V_63 = V_13 ;
} else {
F_2 ( V_22 , L_18
L_19 , V_62 , V_71 , V_3 -> V_72 , V_16 ) ;
if ( F_28 ( V_62 ) ) {
if ( F_29 ( V_3 , V_16 ) )
V_63 = V_36 ;
else
V_63 = V_46 ;
} else {
V_63 = F_30 ( V_62 ) ;
}
}
return V_63 ;
}
int F_31 ( struct V_73 * V_74 , T_3 V_24 , void * V_75 ,
void * * V_76 )
{
struct V_2 * V_3 = V_75 ;
struct V_60 * V_61 = (struct V_60 * ) V_74 -> V_77 ;
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
enum V_1 V_13 = V_36 ;
int V_78 = 0 , V_79 ;
struct V_8 * V_9 = NULL ;
int V_80 ;
T_3 V_10 ;
struct V_81 * V_82 ;
V_10 = F_32 ( V_61 -> V_10 ) ;
if ( V_10 & V_83 ) {
F_2 ( V_22 , L_20 ) ;
return V_84 ;
}
if ( ( V_10 & ( V_40 | V_21 ) ) == ( V_40 | V_21 ) ) {
F_2 ( V_22 , L_21
L_22 ) ;
return V_84 ;
}
if ( V_61 -> V_68 > V_85 ) {
F_2 ( V_22 , L_23 ) ;
return V_86 ;
}
if ( ! F_33 ( V_3 ) )
return V_30 ;
F_34 ( ! F_35 ( V_3 ) ,
L_24 , V_3 -> V_25 ) ;
F_2 ( 0 , L_25 , V_10 & V_40 ? L_26 : L_27 ) ;
V_5 = F_36 ( V_3 , V_61 -> V_25 , V_61 -> V_68 ) ;
if ( ! V_5 ) {
F_2 ( 0 , L_28 ) ;
V_13 = V_30 ;
goto V_87;
}
V_82 = & V_5 -> V_48 ;
V_78 = 0 ;
F_4 ( & V_5 -> V_27 ) ;
if ( V_5 -> V_28 & V_31 ) {
F_6 ( & V_5 -> V_27 ) ;
F_2 ( 0 , L_29 ) ;
V_13 = V_32 ;
goto V_33;
}
if ( V_5 -> V_28 & V_34 ) {
F_6 ( & V_5 -> V_27 ) ;
F_2 ( 0 , L_30 ) ;
V_13 = V_35 ;
goto V_33;
}
if ( V_5 -> V_16 != V_3 -> V_18 ) {
F_6 ( & V_5 -> V_27 ) ;
F_2 ( 0 , L_31 ) ;
V_13 = V_30 ;
goto V_33;
}
for ( V_79 = 0 ; V_79 < 3 ; V_79 ++ ) {
F_37 (lock, queue, list) {
if ( V_7 -> V_49 . V_55 == V_61 -> V_55 &&
V_7 -> V_49 . V_88 == V_61 -> V_67 ) {
F_11 ( V_7 ) ;
V_78 = 1 ;
break;
}
}
if ( V_78 )
break;
V_82 ++ ;
}
F_6 ( & V_5 -> V_27 ) ;
if ( ! V_78 ) {
V_13 = V_89 ;
goto V_87;
}
V_9 = V_7 -> V_9 ;
if ( V_10 & ( V_17 | V_40 ) &&
V_7 -> V_49 . type != V_90 )
V_10 &= ~ ( V_17 | V_40 ) ;
if ( V_10 & V_40 ) {
V_9 -> V_10 |= V_58 ;
memcpy ( & V_9 -> V_38 [ 0 ] , & V_61 -> V_38 [ 0 ] , V_39 ) ;
}
V_13 = F_24 ( V_3 , V_5 , V_7 , V_9 , V_10 , & V_80 ) ;
if ( V_13 == V_30 )
F_2 ( 0 , L_32 ) ;
if ( V_10 & V_40 )
V_9 -> V_10 &= ~ V_58 ;
F_38 ( V_3 , V_5 ) ;
F_39 ( V_3 , V_5 ) ;
V_87:
if ( ! V_78 )
F_2 ( V_22 , L_33
L_34 ,
F_17 ( F_18 ( V_61 -> V_55 ) ) ,
F_19 ( F_18 ( V_61 -> V_55 ) ) ) ;
else
F_13 ( V_7 ) ;
V_33:
if ( V_5 )
F_40 ( V_5 ) ;
F_41 ( V_3 ) ;
return V_13 ;
}
static enum V_1 F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int * V_14 )
{
enum V_1 V_13 ;
if ( F_15 ( & V_5 -> V_91 , V_7 ) ) {
V_13 = V_36 ;
* V_14 = ( V_57 |
V_43 ) ;
} else if ( F_15 ( & V_5 -> V_52 , V_7 ) ) {
V_13 = V_36 ;
* V_14 = ( V_57 |
V_43 |
V_44 |
V_45 ) ;
} else if ( F_15 ( & V_5 -> V_48 , V_7 ) ) {
V_13 = V_37 ;
* V_14 = V_57 ;
} else {
F_2 ( V_22 , L_35 ) ;
V_13 = V_89 ;
* V_14 = 0 ;
}
return V_13 ;
}
static enum V_1 F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int * V_14 )
{
enum V_1 V_13 ;
if ( ! F_15 ( & V_5 -> V_48 , V_7 ) ) {
V_13 = V_92 ;
F_42 ( V_13 ) ;
* V_14 = 0 ;
} else {
V_13 = V_36 ;
* V_14 = ( V_54 |
V_57 |
V_43 ) ;
}
return V_13 ;
}
enum V_1 F_43 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_10 , T_4 * V_93 , void * V_75 )
{
enum V_1 V_13 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = NULL ;
int V_11 , V_94 ;
if ( ! V_9 ) {
F_42 ( V_84 ) ;
return V_84 ;
}
if ( V_10 & ~ ( V_21 | V_17 | V_95 ) ) {
F_42 ( V_26 ) ;
return V_26 ;
}
if ( ( V_10 & ( V_17 | V_21 ) ) == ( V_17 | V_21 ) ) {
F_2 ( 0 , L_36 ) ;
V_10 &= ~ V_17 ;
}
if ( ! V_9 -> V_96 || ! V_9 -> V_96 -> V_97 ) {
F_42 ( V_26 ) ;
return V_26 ;
}
V_7 = V_9 -> V_96 ;
F_3 ( ! V_7 ) ;
F_11 ( V_7 ) ;
V_5 = V_7 -> V_97 ;
F_3 ( ! V_5 ) ;
F_44 ( V_5 ) ;
V_98:
V_11 = 0 ;
F_2 ( 0 , L_37 , V_7 , V_5 ) ;
F_4 ( & V_5 -> V_27 ) ;
V_94 = ( V_5 -> V_16 == V_3 -> V_18 ) ;
if ( V_10 & V_17 && V_7 -> V_49 . type != V_90 )
V_10 &= ~ V_17 ;
F_6 ( & V_5 -> V_27 ) ;
if ( V_94 ) {
V_13 = F_24 ( V_3 , V_5 , V_7 , V_9 , V_10 ,
& V_11 ) ;
F_2 ( 0 , L_38
L_39 , V_13 , V_11 ) ;
} else {
V_13 = F_25 ( V_3 , V_5 , V_7 , V_9 , V_10 ,
& V_11 ) ;
F_2 ( 0 , L_40
L_39 , V_13 , V_11 ) ;
}
if ( V_13 == V_32 ||
V_13 == V_35 ||
V_13 == V_30 ||
V_13 == V_46 ) {
F_45 ( 50 ) ;
F_2 ( 0 , L_41
L_42 ) ;
goto V_98;
}
if ( V_11 ) {
F_2 ( 0 , L_43 , V_75 , V_13 ) ;
if ( V_94 ) {
F_39 ( V_3 , NULL ) ;
F_46 ( V_3 -> V_99 ,
F_47 ( V_3 , V_7 ) ) ;
}
(* V_93)( V_75 , V_13 ) ;
}
if ( V_13 == V_37 )
V_13 = V_36 ;
if ( V_13 == V_36 ) {
F_2 ( 0 , L_44 ) ;
F_39 ( V_3 , V_5 ) ;
} else
F_42 ( V_13 ) ;
F_38 ( V_3 , V_5 ) ;
F_40 ( V_5 ) ;
F_13 ( V_7 ) ;
F_2 ( 0 , L_45 , V_13 ) ;
return V_13 ;
}
