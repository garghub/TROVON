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
struct V_6 * V_18 = NULL ;
F_12 ( & V_5 -> V_12 ) ;
F_13 ( 0 , L_1 ,
V_7 -> V_19 . type , V_7 -> V_19 . V_20 , type ) ;
F_2 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_19 . V_20 != V_21 ) {
F_13 ( V_22 , L_2
L_3 ) ;
V_11 = V_23 ;
goto V_24;
}
if ( ! F_14 ( & V_5 -> V_25 , V_7 ) ) {
F_13 ( V_22 , L_4
L_5 ) ;
V_11 = V_23 ;
goto V_24;
}
if ( V_8 & V_26 ) {
switch ( V_7 -> V_19 . type ) {
case V_27 :
F_13 ( 0 , L_6 ,
F_15 ( V_7 -> V_19 . type ) ,
F_15 ( type ) ) ;
V_7 -> V_28 -> V_8 |= V_29 ;
break;
case V_30 :
case V_31 :
if ( type > V_31 ) {
F_13 ( 0 , L_7
L_8 ,
F_15 ( V_7 -> V_19 . type ) ,
F_15 ( type ) ) ;
V_7 -> V_28 -> V_8 |= V_32 ;
} else {
F_13 ( 0 , L_9
L_10 ,
F_15 ( V_7 -> V_19 . type ) ,
F_15 ( type ) ) ;
V_8 &= ~ ( V_26 ) ;
}
break;
}
}
if ( type <= V_7 -> V_19 . type )
goto V_33;
V_11 = V_16 ;
F_16 (tmplock, &res->granted, list) {
if ( V_18 == V_7 )
continue;
if ( ! F_17 ( V_18 -> V_19 . type , type ) )
goto V_34;
}
F_16 (tmplock, &res->converting, list) {
if ( ! F_17 ( V_18 -> V_19 . type , type ) )
goto V_34;
if ( ! F_17 ( V_18 -> V_19 . V_20 , type ) )
goto V_34;
}
V_33:
F_13 ( 0 , L_11 , V_5 -> V_35 . V_36 ,
V_5 -> V_35 . V_37 , F_15 ( type ) ) ;
V_7 -> V_28 -> V_11 = V_16 ;
if ( V_7 -> V_19 . V_38 == V_3 -> V_39 )
F_13 ( 0 , L_12 ) ;
V_7 -> V_19 . type = type ;
if ( V_7 -> V_28 -> V_8 & V_29 )
memcpy ( V_5 -> V_40 , V_7 -> V_28 -> V_40 , V_41 ) ;
F_18 ( & V_7 -> V_42 , & V_5 -> V_25 ) ;
V_11 = V_16 ;
* V_9 = 1 ;
goto V_24;
V_34:
if ( V_8 & V_43 ) {
F_13 ( 0 , L_13
L_14 , V_5 -> V_35 . V_36 , V_5 -> V_35 . V_37 ,
V_7 -> V_19 . type , type ) ;
V_11 = V_17 ;
goto V_24;
}
F_13 ( 0 , L_15 , V_5 -> V_35 . V_36 ,
V_5 -> V_35 . V_37 ) ;
V_7 -> V_19 . V_20 = type ;
F_18 ( & V_7 -> V_42 , & V_5 -> V_44 ) ;
V_24:
F_6 ( & V_7 -> V_12 ) ;
if ( V_11 == V_23 ) {
F_19 ( V_5 ) ;
}
if ( V_11 == V_16 )
* V_10 = 1 ;
return V_11 ;
}
void F_20 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
F_18 ( & V_7 -> V_42 , & V_5 -> V_25 ) ;
V_7 -> V_19 . V_20 = V_21 ;
V_7 -> V_28 -> V_8 &= ~ ( V_32 | V_29 ) ;
}
enum V_1 F_21 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 , int type )
{
enum V_1 V_11 ;
T_1 V_45 = V_5 -> V_46 ;
F_13 ( 0 , L_16 , V_7 -> V_19 . type ,
V_7 -> V_19 . V_20 , V_5 -> V_13 & V_14 ) ;
F_2 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 & V_47 ) {
F_13 ( 0 , L_17
L_18 ) ;
V_11 = V_48 ;
goto V_49;
}
F_3 ( V_5 ) ;
if ( V_7 -> V_19 . V_20 != V_21 ) {
F_19 ( V_5 ) ;
F_13 ( V_22 , L_19
L_20 ,
F_22 ( F_23 ( V_7 -> V_19 . V_50 ) ) ,
F_24 ( F_23 ( V_7 -> V_19 . V_50 ) ) ,
V_7 -> V_19 . V_20 ) ;
V_11 = V_23 ;
goto V_49;
}
if ( V_7 -> V_19 . type == type && V_7 -> V_19 . V_20 == V_21 ) {
F_13 ( 0 , L_21
L_22
L_23 ,
V_5 -> V_35 . V_36 , V_5 -> V_35 . V_37 ,
F_22 ( F_23 ( V_7 -> V_19 . V_50 ) ) ,
F_24 ( F_23 ( V_7 -> V_19 . V_50 ) ) ,
V_7 -> V_19 . type , V_7 -> V_19 . V_20 ) ;
V_11 = V_16 ;
goto V_49;
}
V_5 -> V_13 |= V_14 ;
F_18 ( & V_7 -> V_42 , & V_5 -> V_44 ) ;
V_7 -> V_51 = 1 ;
V_7 -> V_19 . V_20 = type ;
if ( V_8 & V_26 ) {
if ( V_7 -> V_19 . type == V_27 ) {
V_8 |= V_52 ;
V_7 -> V_28 -> V_8 |= V_29 ;
} else {
if ( V_7 -> V_19 . V_20 == V_31 )
V_8 &= ~ V_26 ;
else {
V_8 |= V_53 ;
V_7 -> V_28 -> V_8 |= V_32 ;
}
}
}
F_6 ( & V_5 -> V_12 ) ;
V_11 = F_25 ( V_3 , V_5 , V_7 , V_8 , type ) ;
F_2 ( & V_5 -> V_12 ) ;
V_5 -> V_13 &= ~ V_14 ;
V_7 -> V_51 = 0 ;
if ( V_11 != V_16 ) {
if ( V_11 != V_17 )
F_8 ( V_11 ) ;
F_20 ( V_5 , V_7 ) ;
} else if ( ( V_5 -> V_13 & V_47 ) ||
( V_45 != V_5 -> V_46 ) ) {
F_13 ( 0 , L_24 ,
V_5 -> V_35 . V_36 , V_5 -> V_35 . V_37 ) ;
V_11 = V_48 ;
}
V_49:
F_6 ( & V_5 -> V_12 ) ;
F_7 ( & V_5 -> V_15 ) ;
return V_11 ;
}
static enum V_1 F_25 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 , int type )
{
struct V_54 V_55 ;
int V_56 ;
enum V_1 V_57 ;
int V_11 = 0 ;
struct V_58 V_59 [ 2 ] ;
T_2 V_60 = 1 ;
F_13 ( 0 , L_25 , V_5 -> V_35 . V_36 , V_5 -> V_35 . V_37 ) ;
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 . V_61 = V_3 -> V_39 ;
V_55 . V_62 = type ;
V_55 . V_50 = V_7 -> V_19 . V_50 ;
V_55 . V_63 = V_5 -> V_35 . V_36 ;
V_55 . V_8 = F_26 ( V_8 ) ;
memcpy ( V_55 . V_37 , V_5 -> V_35 . V_37 , V_55 . V_63 ) ;
V_59 [ 0 ] . V_64 = sizeof( struct V_54 ) ;
V_59 [ 0 ] . V_65 = & V_55 ;
if ( V_8 & V_52 ) {
V_59 [ 1 ] . V_64 = V_41 ;
V_59 [ 1 ] . V_65 = V_7 -> V_28 -> V_40 ;
V_60 ++ ;
}
V_56 = F_27 ( V_66 , V_3 -> V_67 ,
V_59 , V_60 , V_5 -> V_46 , & V_11 ) ;
if ( V_56 >= 0 ) {
V_57 = V_11 ;
if ( V_57 == V_48 ) {
F_13 ( 0 , L_26
L_27 , V_5 -> V_46 ) ;
} else if ( V_57 == V_68 ) {
F_13 ( 0 , L_28
L_27 , V_5 -> V_46 ) ;
} else if ( V_57 == V_69 ) {
F_13 ( 0 , L_29
L_27 , V_5 -> V_46 ) ;
} else if ( V_57 != V_16 && V_57 != V_17 )
F_8 ( V_57 ) ;
} else {
F_13 ( V_22 , L_30
L_31 , V_56 , V_66 , V_3 -> V_67 ,
V_5 -> V_46 ) ;
if ( F_28 ( V_56 ) ) {
F_29 ( V_3 , V_5 -> V_46 ,
V_70 ) ;
V_57 = V_48 ;
F_13 ( 0 , L_32
L_33 , V_5 -> V_46 ) ;
} else {
V_57 = F_30 ( V_56 ) ;
}
}
return V_57 ;
}
int F_31 ( struct V_71 * V_72 , T_3 V_36 , void * V_73 ,
void * * V_74 )
{
struct V_2 * V_3 = V_73 ;
struct V_54 * V_75 = (struct V_54 * ) V_72 -> V_76 ;
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_77 ;
struct V_78 * V_28 ;
enum V_1 V_11 = V_16 ;
T_3 V_8 ;
int V_9 = 0 , V_10 = 0 , V_79 = 0 , V_80 = 0 ;
if ( ! F_32 ( V_3 ) ) {
F_8 ( V_81 ) ;
return V_81 ;
}
F_33 ( ! F_34 ( V_3 ) ,
L_34 , V_3 -> V_37 ) ;
if ( V_75 -> V_63 > V_82 ) {
V_11 = V_83 ;
F_8 ( V_11 ) ;
goto V_84;
}
V_8 = F_35 ( V_75 -> V_8 ) ;
if ( ( V_8 & ( V_52 | V_53 ) ) ==
( V_52 | V_53 ) ) {
F_13 ( V_22 , L_35 ) ;
V_11 = V_85 ;
goto V_84;
}
F_13 ( 0 , L_36 , V_8 & V_52 ? L_37 :
( V_8 & V_53 ? L_38 : L_39 ) ) ;
V_11 = V_86 ;
V_5 = F_36 ( V_3 , V_75 -> V_37 , V_75 -> V_63 ) ;
if ( ! V_5 ) {
F_8 ( V_11 ) ;
goto V_84;
}
F_2 ( & V_5 -> V_12 ) ;
V_11 = F_37 ( V_5 ) ;
if ( V_11 != V_16 ) {
F_6 ( & V_5 -> V_12 ) ;
F_8 ( V_11 ) ;
goto V_84;
}
F_16 (tmp_lock, &res->granted, list) {
if ( V_77 -> V_19 . V_50 == V_75 -> V_50 &&
V_77 -> V_19 . V_38 == V_75 -> V_61 ) {
V_7 = V_77 ;
F_38 ( V_7 ) ;
break;
}
}
F_6 ( & V_5 -> V_12 ) ;
if ( ! V_7 ) {
V_11 = V_86 ;
F_13 ( V_22 , L_40
L_41 ,
F_22 ( F_23 ( V_75 -> V_50 ) ) ,
F_24 ( F_23 ( V_75 -> V_50 ) ) ) ;
F_39 ( V_5 ) ;
goto V_84;
}
V_28 = V_7 -> V_28 ;
if ( V_8 & V_52 ) {
F_40 ( V_28 -> V_8 & ( V_29 | V_32 ) ) ;
V_28 -> V_8 |= V_29 ;
memcpy ( & V_28 -> V_40 [ 0 ] , & V_75 -> V_40 [ 0 ] , V_41 ) ;
} else if ( V_8 & V_53 ) {
F_40 ( V_28 -> V_8 & ( V_29 | V_32 ) ) ;
V_28 -> V_8 |= V_32 ;
}
F_2 ( & V_5 -> V_12 ) ;
V_11 = F_37 ( V_5 ) ;
if ( V_11 == V_16 ) {
F_4 ( V_5 ) ;
V_79 = 1 ;
V_5 -> V_13 |= V_14 ;
V_11 = F_5 ( V_3 , V_5 , V_7 , V_8 ,
V_75 -> V_62 ,
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
V_28 -> V_8 &= ~ ( V_32 | V_29 ) ;
}
V_84:
if ( V_7 )
F_41 ( V_7 ) ;
if ( V_9 )
F_9 ( V_3 , V_7 ) ;
else if ( V_79 )
F_10 ( V_3 , V_5 ) ;
if ( V_10 )
F_11 ( V_3 , V_5 ) ;
if ( V_5 )
F_42 ( V_5 ) ;
F_43 ( V_3 ) ;
return V_11 ;
}
