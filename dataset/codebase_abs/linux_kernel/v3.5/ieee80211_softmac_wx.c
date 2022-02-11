int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
F_2 ( & V_2 -> V_12 ) ;
if( V_2 -> V_13 == V_14 ) {
V_8 = - V_15 ;
goto V_16;
}
if ( V_10 -> V_17 == 1 ) {
if ( ( V_10 -> V_18 >= ( int ) 2.412e8 &&
V_10 -> V_18 <= ( int ) 2.487e8 ) ) {
int V_19 = V_10 -> V_18 / 100000 ;
int V_20 = 0 ;
while ( ( V_20 < 14 ) && ( V_19 != V_21 [ V_20 ] ) )
V_20 ++ ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = V_20 + 1 ;
}
}
if ( V_10 -> V_17 > 0 || V_10 -> V_18 > 14 || V_10 -> V_18 < 1 ) {
V_8 = - V_15 ;
goto V_16;
} else {
V_2 -> V_22 . V_23 = V_10 -> V_18 ;
V_2 -> V_24 ( V_2 -> V_25 , V_2 -> V_22 . V_23 ) ;
if( V_2 -> V_13 == V_26 || V_2 -> V_13 == V_27 )
if( V_2 -> V_28 == V_29 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
}
V_8 = 0 ;
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_2 -> V_22 . V_23 == 0 )
return - 1 ;
V_10 -> V_18 = V_2 -> V_22 . V_23 ;
V_10 -> V_17 = 0 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
unsigned long V_32 ;
V_6 -> V_33 . V_34 = V_35 ;
if ( V_2 -> V_13 == V_36 )
return - 1 ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
if ( V_2 -> V_28 != V_29 &&
V_2 -> V_28 != V_38 &&
V_2 -> V_39 == 0 )
memset ( V_6 -> V_33 . V_40 , 0 , V_41 ) ;
else
memcpy ( V_6 -> V_33 . V_40 ,
V_2 -> V_22 . V_42 , V_41 ) ;
F_9 ( & V_2 -> V_37 , V_32 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_43 ,
char * V_31 )
{
int V_8 = 0 ;
T_1 V_44 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned long V_32 ;
short V_45 = V_2 -> V_46 ;
struct V_47 * V_48 = (struct V_47 * ) V_43 ;
V_2 -> V_49 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_27 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_48 -> V_34 != V_35 ) {
V_8 = - V_50 ;
goto V_16;
}
if ( V_45 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
memcpy ( V_2 -> V_22 . V_42 , V_48 -> V_40 , V_41 ) ;
V_2 -> V_39 = memcmp ( V_48 -> V_40 , V_44 , V_41 ) != 0 ;
F_9 ( & V_2 -> V_37 , V_32 ) ;
if ( V_45 )
F_12 ( V_2 ) ;
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , union V_5 * V_6 , char * V_7 )
{
int V_51 , V_8 = 0 ;
unsigned long V_32 ;
if ( V_2 -> V_13 == V_36 )
return - 1 ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
if ( V_2 -> V_22 . V_52 [ 0 ] == '\0' ||
V_2 -> V_22 . V_53 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_28 != V_29 &&
V_2 -> V_28 != V_38 &&
V_2 -> V_54 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
V_51 = V_2 -> V_22 . V_53 ;
V_6 -> V_55 . V_56 = V_51 ;
strncpy ( V_7 , V_2 -> V_22 . V_52 , V_51 ) ;
V_6 -> V_55 . V_32 = 1 ;
V_16:
F_9 ( & V_2 -> V_37 , V_32 ) ;
return V_8 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
T_2 V_57 = V_6 -> V_58 . V_59 ;
if( V_57 == - 1 ) {
V_2 -> V_60 = 110 ;
} else {
V_2 -> V_60 = V_57 / 100000 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
V_6 -> V_58 . V_59 = V_2 -> V_60 * 100000 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_2 -> V_49 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_61 == V_2 -> V_13 )
goto V_16;
if ( V_6 -> V_61 == V_36 ) {
V_2 -> V_25 -> type = V_62 ;
} else{
V_2 -> V_25 -> type = V_35 ;
}
if ( ! V_2 -> V_46 ) {
V_2 -> V_13 = V_6 -> V_61 ;
} else{
F_11 ( V_2 ) ;
V_2 -> V_13 = V_6 -> V_61 ;
F_12 ( V_2 ) ;
}
V_16:
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
void F_17 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_18 ( V_64 , struct V_1 , V_65 ) ;
short V_66 ;
V_66 = V_2 -> V_22 . V_23 ;
if ( V_2 -> V_67 )
V_2 -> V_67 ( V_2 -> V_25 ) ;
F_3 ( V_2 ) ;
V_2 -> V_28 = V_38 ;
V_2 -> V_68 ( V_2 -> V_25 ) ;
F_19 ( V_2 ) ;
V_2 -> V_24 ( V_2 -> V_25 , V_66 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_68 ( V_2 -> V_25 ) ;
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 -> V_25 ) ;
if( V_2 -> V_13 == V_26 || V_2 -> V_13 == V_27 )
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_12 ) ;
}
int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_36 || ! ( V_2 -> V_46 ) ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_28 == V_29 ) {
F_21 ( V_2 -> V_70 , & V_2 -> V_65 ) ;
return 0 ;
}
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_31 )
{
int V_8 = 0 , V_51 ;
short V_46 ;
unsigned long V_32 ;
V_2 -> V_49 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
V_46 = V_2 -> V_46 ;
if ( V_6 -> V_55 . V_56 > V_71 ) {
V_8 = - V_72 ;
goto V_16;
}
if ( V_2 -> V_13 == V_36 ) {
V_8 = - 1 ;
goto V_16;
}
if( V_46 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
if ( V_6 -> V_55 . V_32 && V_6 -> V_55 . V_56 ) {
V_51 = ( V_6 -> V_55 . V_56 < V_71 ) ? ( V_6 -> V_55 . V_56 ) : V_71 ;
memset ( V_2 -> V_22 . V_52 , 0 , V_2 -> V_22 . V_53 ) ;
strncpy ( V_2 -> V_22 . V_52 , V_31 , V_51 ) ;
V_2 -> V_22 . V_53 = V_51 ;
V_2 -> V_54 = 1 ;
if( V_51 == 0 ) {
memset ( V_2 -> V_22 . V_42 , 0 , V_41 ) ;
V_2 -> V_22 . V_73 = 0 ;
}
}
else{
V_2 -> V_54 = 0 ;
V_2 -> V_22 . V_52 [ 0 ] = '\0' ;
V_2 -> V_22 . V_53 = 0 ;
}
F_9 ( & V_2 -> V_37 , V_32 ) ;
if ( V_46 )
F_12 ( V_2 ) ;
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_6 -> V_61 = V_2 -> V_13 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
int * V_74 = ( int * ) V_31 ;
int V_75 = ( V_74 [ 0 ] > 0 ) ;
short V_76 = V_2 -> V_77 ;
F_2 ( & V_2 -> V_12 ) ;
if( V_75 )
V_2 -> V_77 = 1 ;
else
V_2 -> V_77 = 0 ;
F_25 ( V_78 L_1 ,
V_2 -> V_77 ? L_2 : L_3 ) ;
if( V_2 -> V_13 == V_36 )
{
if( V_76 == 0 && V_2 -> V_77 ) {
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 -> V_25 ) ;
F_26 ( V_2 -> V_25 ) ;
}
if( V_76 && V_2 -> V_77 == 1 )
F_27 ( V_2 -> V_25 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
F_29 ( V_6 -> V_79 , L_4 , V_80 ) ;
if( V_2 -> V_81 & V_82 ) {
F_30 ( V_6 -> V_79 , L_5 , V_80 ) ;
if( V_2 -> V_81 & V_83 )
F_30 ( V_6 -> V_79 , L_6 , V_80 ) ;
} else if( V_2 -> V_81 & V_83 )
F_30 ( V_6 -> V_79 , L_7 , V_80 ) ;
if( ( V_2 -> V_28 == V_29 ) ||
( V_2 -> V_28 == V_38 ) )
F_30 ( V_6 -> V_79 , L_8 , V_80 ) ;
else if( V_2 -> V_28 != V_84 )
F_30 ( V_6 -> V_79 , L_9 , V_80 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
int V_8 = 0 ;
if(
( ! V_2 -> V_85 ) ||
( ! V_2 -> V_86 ) ||
( ! V_2 -> V_87 ) ||
( ! V_2 -> V_88 ) ) {
F_25 ( L_10 ) ;
return - 1 ;
}
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_89 . V_90 ) {
V_2 -> V_91 = V_92 ;
goto exit;
}
switch ( V_6 -> V_89 . V_32 & V_93 ) {
case V_94 :
V_2 -> V_91 = V_95 ;
break;
case V_96 :
V_2 -> V_91 = V_95 | V_97 ;
break;
case V_98 :
V_2 -> V_91 = V_92 ;
break;
default:
V_8 = - V_50 ;
goto exit;
}
if ( V_6 -> V_89 . V_32 & V_99 ) {
V_2 -> V_100 = V_6 -> V_89 . V_59 / 1000 ;
F_25 ( L_11 , V_2 -> V_100 ) ;
}
if ( V_6 -> V_89 . V_32 & V_101 ) {
V_8 = - V_15 ;
goto exit;
}
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_30 ,
union V_5 * V_6 , char * V_31 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if( V_2 -> V_91 == V_92 ) {
V_6 -> V_89 . V_90 = 1 ;
goto exit;
}
V_6 -> V_89 . V_90 = 0 ;
V_6 -> V_89 . V_32 = V_99 ;
V_6 -> V_89 . V_59 = V_2 -> V_100 * 1000 ;
if ( V_2 -> V_91 & V_97 )
V_6 -> V_89 . V_32 |= V_96 ;
else
V_6 -> V_89 . V_32 |= V_94 ;
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
