enum V_1 F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 , int type )
{
int V_9 = 0 , V_10 = 0 ;
enum V_1 V_11 ;
F_2 ( & V_5 -> V_12 ) ;
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
V_5 -> V_13 |= V_14 ;
V_11 = F_5 ( V_3 , V_5 , V_7 , V_8 , type ,
& V_9 , & V_10 ) ;
V_5 -> V_13 &= ~ V_14 ;
F_6 ( & V_5 -> V_12 ) ;
F_7 ( & V_5 -> V_15 ) ;
if ( V_11 != V_16 && V_11 != V_17 )
F_8 ( V_11 ) ;
if ( V_9 )
F_9 ( V_3 , V_7 ) ;
else
F_10 ( V_3 , V_5 ) ;
if ( V_10 )
F_11 ( V_3 , V_5 ) ;
return V_11 ;
}
static enum V_1 F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 ,
int type , int * V_9 ,
int * V_10 )
{
enum V_1 V_11 = V_16 ;
struct V_18 * V_19 ;
struct V_6 * V_20 = NULL ;
F_12 ( & V_5 -> V_12 ) ;
F_13 ( 0 , L_1 ,
V_7 -> V_21 . type , V_7 -> V_21 . V_22 , type ) ;
F_2 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_21 . V_22 != V_23 ) {
F_13 ( V_24 , L_2
L_3 ) ;
V_11 = V_25 ;
goto V_26;
}
if ( ! F_14 ( & V_5 -> V_27 , V_7 ) ) {
F_13 ( V_24 , L_4
L_5 ) ;
V_11 = V_25 ;
goto V_26;
}
if ( V_8 & V_28 ) {
switch ( V_7 -> V_21 . type ) {
case V_29 :
F_13 ( 0 , L_6 ,
F_15 ( V_7 -> V_21 . type ) ,
F_15 ( type ) ) ;
V_7 -> V_30 -> V_8 |= V_31 ;
break;
case V_32 :
case V_33 :
if ( type > V_33 ) {
F_13 ( 0 , L_7
L_8 ,
F_15 ( V_7 -> V_21 . type ) ,
F_15 ( type ) ) ;
V_7 -> V_30 -> V_8 |= V_34 ;
} else {
F_13 ( 0 , L_9
L_10 ,
F_15 ( V_7 -> V_21 . type ) ,
F_15 ( type ) ) ;
V_8 &= ~ ( V_28 ) ;
}
break;
}
}
if ( type <= V_7 -> V_21 . type )
goto V_35;
V_11 = V_16 ;
F_16 (iter, &res->granted) {
V_20 = F_17 ( V_19 , struct V_6 , V_36 ) ;
if ( V_20 == V_7 )
continue;
if ( ! F_18 ( V_20 -> V_21 . type , type ) )
goto V_37;
}
F_16 (iter, &res->converting) {
V_20 = F_17 ( V_19 , struct V_6 , V_36 ) ;
if ( ! F_18 ( V_20 -> V_21 . type , type ) )
goto V_37;
if ( ! F_18 ( V_20 -> V_21 . V_22 , type ) )
goto V_37;
}
V_35:
F_13 ( 0 , L_11 , V_5 -> V_38 . V_39 ,
V_5 -> V_38 . V_40 , F_15 ( type ) ) ;
V_7 -> V_30 -> V_11 = V_16 ;
if ( V_7 -> V_21 . V_41 == V_3 -> V_42 )
F_13 ( 0 , L_12 ) ;
V_7 -> V_21 . type = type ;
if ( V_7 -> V_30 -> V_8 & V_31 )
memcpy ( V_5 -> V_43 , V_7 -> V_30 -> V_43 , V_44 ) ;
V_11 = V_16 ;
* V_9 = 1 ;
goto V_26;
V_37:
if ( V_8 & V_45 ) {
F_13 ( 0 , L_13
L_14 , V_5 -> V_38 . V_39 , V_5 -> V_38 . V_40 ,
V_7 -> V_21 . type , type ) ;
V_11 = V_17 ;
goto V_26;
}
F_13 ( 0 , L_15 , V_5 -> V_38 . V_39 ,
V_5 -> V_38 . V_40 ) ;
V_7 -> V_21 . V_22 = type ;
F_19 ( & V_7 -> V_36 , & V_5 -> V_46 ) ;
V_26:
F_6 ( & V_7 -> V_12 ) ;
if ( V_11 == V_25 ) {
F_20 ( V_5 ) ;
}
if ( V_11 == V_16 )
* V_10 = 1 ;
return V_11 ;
}
void F_21 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_36 , & V_5 -> V_27 ) ;
V_7 -> V_21 . V_22 = V_23 ;
V_7 -> V_30 -> V_8 &= ~ ( V_34 | V_31 ) ;
}
enum V_1 F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 , int type )
{
enum V_1 V_11 ;
F_13 ( 0 , L_16 , V_7 -> V_21 . type ,
V_7 -> V_21 . V_22 , V_5 -> V_13 & V_14 ) ;
F_2 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 & V_47 ) {
F_13 ( 0 , L_17
L_18 ) ;
V_11 = V_48 ;
goto V_49;
}
F_3 ( V_5 ) ;
if ( V_7 -> V_21 . V_22 != V_23 ) {
F_20 ( V_5 ) ;
F_13 ( V_24 , L_19
L_20 ,
F_23 ( F_24 ( V_7 -> V_21 . V_50 ) ) ,
F_25 ( F_24 ( V_7 -> V_21 . V_50 ) ) ,
V_7 -> V_21 . V_22 ) ;
V_11 = V_25 ;
goto V_49;
}
V_5 -> V_13 |= V_14 ;
F_19 ( & V_7 -> V_36 , & V_5 -> V_46 ) ;
V_7 -> V_51 = 1 ;
V_7 -> V_21 . V_22 = type ;
if ( V_8 & V_28 ) {
if ( V_7 -> V_21 . type == V_29 ) {
V_8 |= V_52 ;
V_7 -> V_30 -> V_8 |= V_31 ;
} else {
if ( V_7 -> V_21 . V_22 == V_33 )
V_8 &= ~ V_28 ;
else {
V_8 |= V_53 ;
V_7 -> V_30 -> V_8 |= V_34 ;
}
}
}
F_6 ( & V_5 -> V_12 ) ;
V_11 = F_26 ( V_3 , V_5 , V_7 , V_8 , type ) ;
F_2 ( & V_5 -> V_12 ) ;
V_5 -> V_13 &= ~ V_14 ;
V_7 -> V_51 = 0 ;
if ( V_11 != V_16 ) {
if ( V_11 != V_17 )
F_8 ( V_11 ) ;
F_21 ( V_5 , V_7 ) ;
}
V_49:
F_6 ( & V_5 -> V_12 ) ;
F_7 ( & V_5 -> V_15 ) ;
return V_11 ;
}
static enum V_1 F_26 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 , int type )
{
struct V_54 V_55 ;
int V_56 ;
enum V_1 V_57 ;
int V_11 = 0 ;
struct V_58 V_59 [ 2 ] ;
T_1 V_60 = 1 ;
F_13 ( 0 , L_21 , V_5 -> V_38 . V_39 , V_5 -> V_38 . V_40 ) ;
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 . V_61 = V_3 -> V_42 ;
V_55 . V_62 = type ;
V_55 . V_50 = V_7 -> V_21 . V_50 ;
V_55 . V_63 = V_5 -> V_38 . V_39 ;
V_55 . V_8 = F_27 ( V_8 ) ;
memcpy ( V_55 . V_40 , V_5 -> V_38 . V_40 , V_55 . V_63 ) ;
V_59 [ 0 ] . V_64 = sizeof( struct V_54 ) ;
V_59 [ 0 ] . V_65 = & V_55 ;
if ( V_8 & V_52 ) {
V_59 [ 1 ] . V_64 = V_44 ;
V_59 [ 1 ] . V_65 = V_7 -> V_30 -> V_43 ;
V_60 ++ ;
}
V_56 = F_28 ( V_66 , V_3 -> V_67 ,
V_59 , V_60 , V_5 -> V_68 , & V_11 ) ;
if ( V_56 >= 0 ) {
V_57 = V_11 ;
if ( V_57 == V_48 ) {
F_13 ( 0 , L_22
L_23 , V_5 -> V_68 ) ;
} else if ( V_57 == V_69 ) {
F_13 ( 0 , L_24
L_23 , V_5 -> V_68 ) ;
} else if ( V_57 == V_70 ) {
F_13 ( 0 , L_25
L_23 , V_5 -> V_68 ) ;
} else if ( V_57 != V_16 && V_57 != V_17 )
F_8 ( V_57 ) ;
} else {
F_13 ( V_24 , L_26
L_27 , V_56 , V_66 , V_3 -> V_67 ,
V_5 -> V_68 ) ;
if ( F_29 ( V_56 ) ) {
F_30 ( V_3 , V_5 -> V_68 ,
V_71 ) ;
V_57 = V_48 ;
F_13 ( 0 , L_28
L_29 , V_5 -> V_68 ) ;
} else {
V_57 = F_31 ( V_56 ) ;
}
}
return V_57 ;
}
int F_32 ( struct V_72 * V_73 , T_2 V_39 , void * V_74 ,
void * * V_75 )
{
struct V_2 * V_3 = V_74 ;
struct V_54 * V_76 = (struct V_54 * ) V_73 -> V_77 ;
struct V_4 * V_5 = NULL ;
struct V_18 * V_19 ;
struct V_6 * V_7 = NULL ;
struct V_78 * V_30 ;
enum V_1 V_11 = V_16 ;
T_2 V_8 ;
int V_9 = 0 , V_10 = 0 , V_79 = 0 , V_80 = 0 ;
if ( ! F_33 ( V_3 ) ) {
F_8 ( V_81 ) ;
return V_81 ;
}
F_34 ( ! F_35 ( V_3 ) ,
L_30 , V_3 -> V_40 ) ;
if ( V_76 -> V_63 > V_82 ) {
V_11 = V_83 ;
F_8 ( V_11 ) ;
goto V_84;
}
V_8 = F_36 ( V_76 -> V_8 ) ;
if ( ( V_8 & ( V_52 | V_53 ) ) ==
( V_52 | V_53 ) ) {
F_13 ( V_24 , L_31 ) ;
V_11 = V_85 ;
goto V_84;
}
F_13 ( 0 , L_32 , V_8 & V_52 ? L_33 :
( V_8 & V_53 ? L_34 : L_35 ) ) ;
V_11 = V_86 ;
V_5 = F_37 ( V_3 , V_76 -> V_40 , V_76 -> V_63 ) ;
if ( ! V_5 ) {
F_8 ( V_11 ) ;
goto V_84;
}
F_2 ( & V_5 -> V_12 ) ;
V_11 = F_38 ( V_5 ) ;
if ( V_11 != V_16 ) {
F_6 ( & V_5 -> V_12 ) ;
F_8 ( V_11 ) ;
goto V_84;
}
F_16 (iter, &res->granted) {
V_7 = F_17 ( V_19 , struct V_6 , V_36 ) ;
if ( V_7 -> V_21 . V_50 == V_76 -> V_50 &&
V_7 -> V_21 . V_41 == V_76 -> V_61 ) {
F_39 ( V_7 ) ;
break;
}
V_7 = NULL ;
}
F_6 ( & V_5 -> V_12 ) ;
if ( ! V_7 ) {
V_11 = V_86 ;
F_13 ( V_24 , L_36
L_37 ,
F_23 ( F_24 ( V_76 -> V_50 ) ) ,
F_25 ( F_24 ( V_76 -> V_50 ) ) ) ;
F_40 ( V_5 ) ;
goto V_84;
}
V_30 = V_7 -> V_30 ;
if ( V_8 & V_52 ) {
F_41 ( V_30 -> V_8 & ( V_31 | V_34 ) ) ;
V_30 -> V_8 |= V_31 ;
memcpy ( & V_30 -> V_43 [ 0 ] , & V_76 -> V_43 [ 0 ] , V_44 ) ;
} else if ( V_8 & V_53 ) {
F_41 ( V_30 -> V_8 & ( V_31 | V_34 ) ) ;
V_30 -> V_8 |= V_34 ;
}
F_2 ( & V_5 -> V_12 ) ;
V_11 = F_38 ( V_5 ) ;
if ( V_11 == V_16 ) {
F_4 ( V_5 ) ;
V_79 = 1 ;
V_5 -> V_13 |= V_14 ;
V_11 = F_5 ( V_3 , V_5 , V_7 , V_8 ,
V_76 -> V_62 ,
& V_9 , & V_10 ) ;
V_5 -> V_13 &= ~ V_14 ;
V_80 = 1 ;
}
F_6 ( & V_5 -> V_12 ) ;
if ( V_80 )
F_7 ( & V_5 -> V_15 ) ;
if ( V_11 != V_16 ) {
if ( V_11 != V_17 )
F_8 ( V_11 ) ;
V_30 -> V_8 &= ~ ( V_34 | V_31 ) ;
}
V_84:
if ( V_7 )
F_42 ( V_7 ) ;
if ( V_9 )
F_9 ( V_3 , V_7 ) ;
else if ( V_79 )
F_10 ( V_3 , V_5 ) ;
if ( V_10 )
F_11 ( V_3 , V_5 ) ;
if ( V_5 )
F_43 ( V_5 ) ;
F_44 ( V_3 ) ;
return V_11 ;
}
