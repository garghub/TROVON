static int F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 , * V_5 ;
if ( V_1 -> V_6 != 0 ) {
if ( ! ( * V_3 -> V_7 & V_8 ) ) {
if ( ( V_1 -> V_6 - 1 ) == ( * V_3 -> V_7 & V_9 ) ) {
V_1 -> V_6 = * V_3 -> V_7 & V_9 ;
F_2 ( V_3 , 1 ) ;
V_1 -> V_10 += V_3 -> V_11 ;
F_3 ( & V_1 -> V_12 , V_3 ) ;
if ( V_1 -> V_6 == 0 ) {
V_4 = F_4 ( V_13 +
V_1 -> V_10 ,
V_14 ) ;
if ( ! V_4 ) {
F_5 ( & V_1 -> V_12 ) ;
return 1 ;
}
F_6 ( V_4 , V_13 ) ;
V_4 -> V_15 = V_1 -> V_16 -> V_15 ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
while ( ( V_5 = F_9 ( & V_1 -> V_12 ) ) != NULL ) {
F_10 ( V_5 ,
F_11 ( V_4 , V_5 -> V_11 ) ,
V_5 -> V_11 ) ;
F_12 ( V_5 ) ;
}
V_1 -> V_10 = 0 ;
if ( F_13 ( V_1 , V_4 ) == 0 )
F_12 ( V_4 ) ;
}
return 1 ;
}
}
} else {
if ( * V_3 -> V_7 & V_8 ) {
F_5 ( & V_1 -> V_12 ) ;
V_1 -> V_6 = * V_3 -> V_7 & V_9 ;
F_2 ( V_3 , 1 ) ;
V_1 -> V_10 = V_3 -> V_11 ;
F_3 ( & V_1 -> V_12 , V_3 ) ;
return 1 ;
}
}
return 0 ;
}
int F_13 ( T_1 * V_1 , struct V_2 * V_3 )
{
int (* F_14)( struct V_2 * , T_1 * );
unsigned char V_17 ;
int V_18 = 0 ;
if ( V_3 == NULL ) return 0 ;
F_15 ( V_1 ) ;
V_17 = * V_3 -> V_7 ;
if ( V_17 == V_19 ) {
struct V_2 * V_4 = F_16 ( V_3 , V_14 ) ;
if ( V_4 != NULL ) {
F_12 ( V_3 ) ;
V_3 = V_4 ;
}
F_2 ( V_3 , 1 ) ;
V_3 -> V_20 = V_3 -> V_21 ;
F_7 ( V_3 ) ;
V_3 -> V_15 = V_1 -> V_16 -> V_15 ;
V_3 -> V_22 = V_23 ;
V_3 -> V_24 = F_17 ( V_25 ) ;
F_18 ( V_3 ) ;
return 1 ;
}
if ( V_17 == V_26 ) {
F_2 ( V_3 , 1 ) ;
return F_1 ( V_1 , V_3 ) ;
}
if ( ( F_14 = F_19 ( V_17 ) ) != NULL ) {
F_2 ( V_3 , 1 ) ;
return (* F_14)( V_3 , V_1 ) ;
}
if ( V_1 -> V_27 != NULL && V_1 -> V_16 -> V_28 [ V_29 ] == 2 ) {
if ( ( ! V_1 -> V_30 && V_1 -> V_27 -> V_31 == V_17 ) ||
V_1 -> V_30 ) {
if ( F_20 ( V_1 -> V_27 , V_3 ) == 0 )
V_18 = 1 ;
else
V_1 -> V_32 |= V_33 ;
}
}
return V_18 ;
}
static int F_21 ( T_1 * V_1 , struct V_2 * V_3 , int type , int V_34 )
{
int V_18 = 0 ;
if ( V_1 -> V_35 == V_36 )
return 0 ;
switch ( V_1 -> V_16 -> V_28 [ V_37 ] ) {
case V_38 :
case V_39 :
V_18 = F_22 ( V_1 , V_3 , type ) ;
break;
#ifdef F_23
case V_40 :
if ( V_34 || V_1 -> V_16 -> V_34 . V_41 )
V_18 = F_24 ( V_1 , V_3 , type ) ;
else
V_18 = F_22 ( V_1 , V_3 , type ) ;
break;
#endif
}
return V_18 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_42 * V_15 ,
T_2 * V_43 , struct V_44 * V_45 )
{
T_2 V_46 , V_47 , * V_48 = NULL ;
int type = 0 , V_49 = 0 , V_34 ;
struct V_50 * V_51 , * V_27 ;
T_3 V_52 , V_53 ;
T_1 * V_1 ;
V_16 * V_16 ;
F_8 ( V_3 ) ;
if ( ( V_16 = F_26 ( V_15 ) ) == NULL )
goto free;
if ( F_27 ( V_3 -> V_7 , V_3 -> V_11 , & V_46 , & V_47 , & V_52 , & type , & V_34 ) == NULL )
goto free;
if ( V_52 . V_54 + 1 < V_52 . V_55 )
V_48 = & V_52 . V_56 [ V_52 . V_54 + 1 ] ;
F_2 ( V_3 , F_28 ( & V_52 ) ) ;
if ( F_29 ( & V_47 , V_43 ) == 0 && V_52 . V_54 + 1 == V_52 . V_55 )
V_49 = 1 ;
if ( ! V_49 && F_30 ( & V_47 , V_15 ) && V_52 . V_54 + 1 == V_52 . V_55 )
V_49 = 1 ;
if ( ( * V_3 -> V_7 & ~ 0x10 ) == V_57 && V_52 . V_54 + 1 == V_52 . V_55 ) {
F_31 ( V_3 , 2 ) ;
F_32 ( & V_47 , V_3 , V_3 -> V_7 [ 1 ] ) ;
if ( ! V_49 && F_29 ( & V_47 , ( T_2 * ) V_15 -> V_58 ) != 0 )
goto free;
switch ( V_3 -> V_7 [ 1 ] ) {
case V_19 :
F_2 ( V_3 , 2 ) ;
F_8 ( V_3 ) ;
F_7 ( V_3 ) ;
V_3 -> V_15 = V_15 ;
V_3 -> V_22 = V_23 ;
V_3 -> V_24 = F_17 ( V_25 ) ;
F_18 ( V_3 ) ;
break;
case V_59 :
F_2 ( V_3 , 2 ) ;
F_8 ( V_3 ) ;
F_7 ( V_3 ) ;
V_3 -> V_15 = V_15 ;
V_3 -> V_22 = V_23 ;
V_3 -> V_24 = F_17 ( V_60 ) ;
F_18 ( V_3 ) ;
break;
case V_61 :
V_27 = F_33 ( & V_47 , & V_46 , V_62 ) ;
if ( V_27 != NULL ) {
F_34 ( V_27 ) ;
if ( F_35 ( & V_27 -> V_63 ) >=
V_27 -> V_64 ) {
F_12 ( V_3 ) ;
} else {
F_2 ( V_3 , 2 ) ;
if ( F_20 ( V_27 , V_3 ) != 0 )
F_12 ( V_3 ) ;
}
F_36 ( V_27 ) ;
F_37 ( V_27 ) ;
} else {
F_12 ( V_3 ) ;
}
break;
default:
F_12 ( V_3 ) ;
break;
}
return 0 ;
}
if ( V_16 -> V_28 [ V_29 ] == 0 )
goto free;
F_38 ( & V_52 , & V_53 ) ;
if ( ( V_1 = F_39 ( & V_47 , & V_46 , & V_53 , V_15 ) ) != NULL ) {
if ( F_21 ( V_1 , V_3 , type , V_34 ) == 0 )
F_12 ( V_3 ) ;
F_40 ( V_1 ) ;
return 0 ;
}
if ( ( * V_3 -> V_7 & ~ V_65 ) != V_66 &&
( * V_3 -> V_7 & ~ V_65 ) != V_67 ) {
if ( ( * V_3 -> V_7 & ~ V_65 ) != V_68 && V_49 )
F_41 ( V_15 , & V_46 , & V_47 , & V_52 ) ;
goto free;
}
if ( V_52 . V_54 + 1 == V_52 . V_55 )
V_27 = F_42 ( & V_47 , 0 , V_15 , V_69 ) ;
else
V_27 = F_42 ( V_48 , 1 , V_15 , V_69 ) ;
if ( V_27 != NULL ) {
F_34 ( V_27 ) ;
if ( F_43 ( V_27 ) ||
( V_51 = F_44 ( V_27 , V_16 ) ) == NULL ) {
if ( V_49 )
F_41 ( V_15 , & V_46 , & V_47 , & V_52 ) ;
F_12 ( V_3 ) ;
F_36 ( V_27 ) ;
F_37 ( V_27 ) ;
return 0 ;
}
V_1 = F_45 ( V_51 ) ;
F_46 ( V_3 , V_51 ) ;
F_47 ( & V_27 -> V_70 , V_3 ) ;
V_51 -> V_71 = V_72 ;
V_27 -> V_73 ++ ;
F_36 ( V_27 ) ;
} else {
if ( ! V_49 )
goto free;
if ( ( V_1 = F_48 () ) == NULL ) {
F_41 ( V_15 , & V_46 , & V_47 , & V_52 ) ;
goto free;
}
F_49 ( V_1 , V_16 ) ;
}
V_1 -> V_74 = V_47 ;
V_1 -> V_75 = V_46 ;
if ( V_52 . V_55 && ! V_1 -> V_76 &&
( V_1 -> V_76 = F_50 ( sizeof( T_3 ) , V_14 ) ) == NULL ) {
F_12 ( V_3 ) ;
F_51 ( V_1 ) ;
if ( V_27 )
F_37 ( V_27 ) ;
return 0 ;
}
if ( V_52 . V_55 == 0 ) {
F_52 ( V_1 -> V_76 ) ;
V_1 -> V_76 = NULL ;
} else {
memcpy ( V_1 -> V_76 , & V_53 , sizeof( T_3 ) ) ;
}
if ( ( * V_3 -> V_7 & ~ V_65 ) == V_67 ) {
V_1 -> V_77 = V_78 ;
V_1 -> V_79 = V_16 -> V_28 [ V_80 ] ;
} else {
V_1 -> V_77 = V_81 ;
V_1 -> V_79 = V_16 -> V_28 [ V_82 ] ;
}
F_53 ( V_1 , V_83 , V_84 , V_85 ) ;
#ifdef F_23
if ( V_34 && V_1 -> V_16 -> V_28 [ V_37 ] == V_40 )
F_54 ( V_1 ) ;
#endif
V_1 -> V_35 = V_86 ;
F_55 ( V_1 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
F_15 ( V_1 ) ;
if ( V_27 ) {
if ( ! F_58 ( V_27 , V_87 ) )
V_27 -> V_88 ( V_27 ) ;
F_37 ( V_27 ) ;
} else {
free:
F_12 ( V_3 ) ;
}
return 0 ;
}
int F_59 ( struct V_2 * V_3 , struct V_42 * V_15 ,
struct V_44 * V_45 , struct V_42 * V_89 )
{
F_60 ( V_3 ) ;
if ( ! F_61 ( F_62 ( V_15 ) , & V_90 ) ) {
F_12 ( V_3 ) ;
return 0 ;
}
if ( ( * V_3 -> V_7 & 0x0F ) != 0 ) {
F_12 ( V_3 ) ;
return 0 ;
}
F_2 ( V_3 , V_91 ) ;
return F_25 ( V_3 , V_15 , ( T_2 * ) V_15 -> V_43 , V_45 ) ;
}
