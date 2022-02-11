int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
unsigned int V_14 , V_15 , V_16 ;
int V_17 , V_18 , V_19 = 0 ;
void * V_20 = NULL ;
F_2 ( V_2 -> V_21 , L_1 ) ;
F_3 ( ! V_3 ) ;
V_7 = (struct V_6 * ) V_3 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_22 = V_7 -> V_23 ;
V_5 . V_24 = V_7 -> V_25 ;
V_5 . V_26 = V_7 -> V_27 . V_26 ;
V_5 . V_28 [ 0 ] . V_29 =
V_7 -> V_27 . V_28 [ 0 ] . V_29 ;
V_5 . V_28 [ 0 ] . V_30 =
V_7 -> V_27 . V_28 [ 0 ] . V_30 ;
V_5 . V_31 = V_7 -> V_27 . V_31 ;
memcpy ( & V_5 . V_32 , & V_7 -> V_33 ,
sizeof( struct V_34 ) ) ;
V_18 = F_4 ( V_7 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_17 < V_18 )
V_5 . V_32 . V_35 . V_36 . V_37 [ V_17 ] = V_17 ;
else
V_5 . V_32 . V_35 . V_36 . V_37 [ V_17 ] = 0xFF ;
}
V_14 = V_7 -> V_38 ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( V_11 == NULL ) {
F_6 ( V_2 -> V_21 , L_2 ) ;
return - V_39 ;
}
V_15 = V_7 -> V_40 ;
V_16 = V_7 -> V_41 ;
V_2 -> V_42 [ V_14 ] . V_15 = V_15 ;
V_2 -> V_42 [ V_14 ] . V_16 = V_16 ;
V_2 -> V_42 [ V_14 ] . V_18 = V_18 ;
if ( V_2 -> V_43 . V_44 )
V_5 . V_45 = V_2 -> V_43 . V_46 +
V_2 -> V_47 + ( V_14 * sizeof( V_9 ) ) ;
else
V_5 . V_45 = V_2 -> V_48 +
V_2 -> V_47 + ( V_14 * sizeof( V_9 ) ) ;
F_2 ( V_2 -> V_21 , L_3 ,
V_5 . V_45 ) ;
F_2 ( V_2 -> V_21 , L_4 ,
V_15 , V_16 ) ;
F_7 ( & V_2 -> V_42 [ V_14 ] , V_5 . V_24 ,
V_14 , V_5 . V_22 , 0 ) ;
F_2 ( V_2 -> V_21 , L_5 ,
V_14 , V_15 ) ;
V_19 = F_8 ( V_2 , V_16 , V_49 ,
V_50 , V_15 , sizeof( V_5 ) ,
& V_5 , & V_20 , true , true , false , true ) ;
if ( V_19 < 0 ) {
F_6 ( V_2 -> V_21 , L_6 , V_19 ) ;
V_11 -> V_51 = V_52 ;
V_14 = V_19 ;
} else if ( V_20 ) {
V_13 = (struct V_12 * ) V_20 ;
V_19 = V_13 -> V_53 . V_54 ;
if ( ! V_19 )
goto V_55;
F_6 ( V_2 -> V_21 , L_6 , V_19 ) ;
if ( V_19 == V_56 ) {
F_6 ( V_2 -> V_21 ,
L_7 , V_14 ) ;
F_9 ( V_2 , V_14 ) ;
}
V_14 = - V_19 ;
}
V_55:
F_10 ( V_20 ) ;
return V_14 ;
}
int F_11 ( struct V_1 * V_2 , int V_14 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
T_1 V_20 = 0 ;
F_2 ( V_2 -> V_21 , L_8 , V_14 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
if ( V_11 -> V_51 != V_58 )
return - V_59 ;
V_57 = F_8 ( V_2 , V_11 -> V_16 ,
V_49 , V_60 , V_11 -> V_15 ,
sizeof( T_1 ) , & V_20 , NULL , true , true , true , false ) ;
return V_57 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{ struct V_63 * V_64 = NULL ;
T_2 V_65 ;
int V_66 , V_19 = 0 ;
struct V_67 * V_68 = NULL ;
F_2 ( V_2 -> V_21 ,
L_9 ,
V_62 -> type , V_62 -> V_69 , V_62 -> V_68 , V_62 -> V_16 ,
V_62 -> V_15 , V_62 -> V_70 ) ;
if ( F_13 ( & V_64 , true ) )
return - V_71 ;
V_66 = F_14 ( V_2 ) ;
F_15 ( & V_64 -> V_72 , V_62 -> V_69 ,
V_62 -> V_16 , 1 , V_66 ) ;
V_64 -> V_72 . V_73 . V_74 . V_75 . V_76 = V_62 -> V_68 ;
V_65 = V_62 -> V_70 ;
V_64 -> V_72 . V_73 . V_77 = V_65 ;
F_2 ( V_2 -> V_21 , L_10 , V_65 ) ;
memcpy ( V_64 -> V_78 , & V_62 -> V_62 , V_62 -> V_70 ) ;
if ( V_62 -> V_68 ) {
V_68 = F_16 ( V_2 , V_62 -> V_69 , V_66 ) ;
if ( V_68 == NULL ) {
F_10 ( V_64 ) ;
V_19 = - V_71 ;
goto V_55;
}
}
F_17 ( V_2 , V_64 ) ;
F_2 ( V_2 -> V_21 , L_11 ,
V_64 -> V_72 . V_73 . V_77 ) ;
if ( V_62 -> V_68 ) {
V_19 = F_18 ( V_2 , V_68 ) ;
if ( V_19 ) {
F_6 ( V_2 -> V_21 , L_12 , V_19 ) ;
F_19 ( V_2 , V_68 ) ;
goto V_55;
}
}
if ( V_62 -> type == V_79 ) {
if ( V_62 -> V_68 ) {
unsigned char * V_80 = V_68 -> V_20 ;
F_2 ( V_2 -> V_21 , L_13 ,
V_62 -> V_70 ) ;
memcpy ( V_62 -> V_62 , V_80 , V_62 -> V_70 ) ;
}
}
if ( V_62 -> V_68 )
F_19 ( V_2 , V_68 ) ;
V_55:
F_20 ( V_66 , & V_2 -> V_66 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_14 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
F_2 ( V_2 -> V_21 , L_14 , V_14 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
if ( V_11 -> V_51 == V_81 )
return 0 ;
if ( V_11 -> V_51 == V_58 ||
V_11 -> V_51 == V_82 ) {
if ( V_11 -> V_83 == V_52 )
return - V_59 ;
V_57 = F_8 ( V_2 , V_11 -> V_16 , V_49 ,
V_84 , V_11 -> V_15 ,
0 , NULL , NULL , true , true , false , true ) ;
if ( V_57 == 0 ) {
V_11 -> V_83 = V_11 -> V_51 ;
V_11 -> V_51 = V_81 ;
} else if ( V_57 == V_85 ) {
V_57 = - V_39 ;
F_22 ( & V_2 -> V_86 ) ;
F_23 ( V_11 ) ;
F_24 ( & V_2 -> V_86 ) ;
}
} else {
V_57 = - V_59 ;
F_2 ( V_2 -> V_21 , L_15 ) ;
}
return V_57 ;
}
int F_25 ( struct V_1 * V_2 , int V_14 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
F_2 ( V_2 -> V_21 , L_16 , V_14 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
if ( V_11 -> V_51 == V_58 )
return 0 ;
if ( V_11 -> V_51 == V_81 ) {
V_57 = F_8 ( V_2 , V_11 -> V_16 ,
V_49 , V_87 ,
V_11 -> V_15 , 0 , NULL , NULL ,
true , true , false , true ) ;
if ( ! V_57 ) {
if ( V_11 -> V_83 == V_58 )
V_11 -> V_51 = V_58 ;
else
V_11 -> V_51 = V_82 ;
V_11 -> V_83 = V_81 ;
} else if ( V_57 == - V_85 ) {
V_57 = - V_39 ;
F_22 ( & V_2 -> V_86 ) ;
F_23 ( V_11 ) ;
F_24 ( & V_2 -> V_86 ) ;
}
} else {
V_57 = - V_59 ;
F_6 ( V_2 -> V_21 , L_17 ) ;
}
return V_57 ;
}
int F_26 ( struct V_1 * V_2 , int V_14 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
F_2 ( V_2 -> V_21 , L_18 , V_14 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
if ( V_11 -> V_51 != V_52 ) {
V_11 -> V_83 = V_52 ;
V_11 -> V_51 = V_82 ;
V_11 -> V_88 = 0 ;
V_57 = F_8 ( V_2 , V_11 -> V_16 ,
V_49 , V_89 ,
V_11 -> V_15 , 0 , NULL , NULL ,
true , true , true , false ) ;
} else {
V_57 = - V_59 ;
F_2 ( V_2 -> V_21 , L_19 ,
V_11 -> V_51 ) ;
}
return V_57 ;
}
int F_27 ( struct V_1 * V_2 ,
int V_14 , bool V_90 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
F_2 ( V_2 -> V_21 , L_20 , V_14 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
if ( V_11 -> V_51 != V_58 &&
V_11 -> V_51 != V_82 &&
V_11 -> V_51 != V_81 ) {
F_6 ( V_2 -> V_21 , L_21 ,
V_11 -> V_51 ) ;
return - V_59 ;
}
V_57 = F_8 ( V_2 , V_11 -> V_16 , V_49 ,
V_91 , V_11 -> V_15 ,
sizeof( V_92 ) , & V_90 , NULL , true , true , false , false ) ;
return V_57 ;
}
int F_9 ( struct V_1 * V_2 , int V_14 )
{
int V_57 = 0 ;
struct V_10 * V_11 ;
struct V_93 * V_23 ;
F_2 ( V_2 -> V_21 , L_22 , V_14 ) ;
F_22 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_94 == V_95 ) {
F_24 ( & V_2 -> V_86 ) ;
return - V_96 ;
}
F_24 ( & V_2 -> V_86 ) ;
V_11 = F_5 ( V_2 , V_14 ) ;
if ( ! V_11 )
return - V_39 ;
V_23 = V_2 -> V_23 ;
F_22 ( & V_11 -> V_97 ) ;
if ( V_11 -> V_51 != V_52 ) {
V_11 -> V_83 = V_11 -> V_51 ;
V_11 -> V_51 = V_52 ;
F_24 ( & V_11 -> V_97 ) ;
F_2 ( V_2 -> V_21 , L_23 ,
V_14 , V_11 -> V_15 ) ;
V_57 = F_8 ( V_2 , V_11 -> V_16 , V_49 ,
V_98 , V_11 -> V_15 , 0 ,
NULL , NULL , true , true , false , true ) ;
F_2 ( V_2 -> V_21 , L_24 ,
V_57 ) ;
F_22 ( & V_2 -> V_86 ) ;
F_23 ( V_11 ) ;
F_24 ( & V_2 -> V_86 ) ;
F_2 ( V_2 -> V_21 , L_25 ) ;
} else {
F_24 ( & V_11 -> V_97 ) ;
V_57 = - V_59 ;
F_2 ( V_2 -> V_21 , L_26 ) ;
}
return V_57 ;
}
