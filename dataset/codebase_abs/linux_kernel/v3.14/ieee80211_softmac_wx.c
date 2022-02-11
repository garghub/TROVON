int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
int V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
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
if ( V_2 -> V_13 == V_26 || V_2 -> V_13 == V_27 )
if ( V_2 -> V_28 == V_29 ) {
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
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_2 -> V_22 . V_23 == 0 )
return - 1 ;
V_10 -> V_18 = V_2 -> V_22 . V_23 ;
V_10 -> V_17 = 0 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
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
struct V_3 * V_30 , union V_5 * V_43 ,
char * V_31 )
{
int V_8 = 0 ;
unsigned long V_32 ;
short V_44 = V_2 -> V_45 ;
struct V_46 * V_47 = (struct V_46 * ) V_43 ;
V_2 -> V_48 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_27 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_47 -> V_34 != V_35 ) {
V_8 = - V_49 ;
goto V_16;
}
if ( V_44 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
memcpy ( V_2 -> V_22 . V_42 , V_47 -> V_40 , V_41 ) ;
V_2 -> V_39 = ! F_12 ( V_47 -> V_40 ) ;
F_9 ( & V_2 -> V_37 , V_32 ) ;
if ( V_44 )
F_13 ( V_2 ) ;
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
int V_50 , V_8 = 0 ;
unsigned long V_32 ;
if ( V_2 -> V_13 == V_36 )
return - 1 ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
if ( V_2 -> V_22 . V_51 [ 0 ] == '\0' ||
V_2 -> V_22 . V_52 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_28 != V_29 &&
V_2 -> V_28 != V_38 &&
V_2 -> V_53 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
V_50 = V_2 -> V_22 . V_52 ;
V_6 -> V_54 . V_55 = V_50 ;
strncpy ( V_7 , V_2 -> V_22 . V_51 , V_50 ) ;
V_6 -> V_54 . V_32 = 1 ;
V_16:
F_9 ( & V_2 -> V_37 , V_32 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
T_1 V_56 = V_6 -> V_57 . V_58 ;
if ( V_56 == - 1 )
V_2 -> V_59 = 110 ;
else
V_2 -> V_59 = V_56 / 100000 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
V_6 -> V_57 . V_58 = V_2 -> V_59 * 100000 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
V_2 -> V_48 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_60 == V_2 -> V_13 )
goto V_16;
if ( V_6 -> V_60 == V_36 )
V_2 -> V_25 -> type = V_61 ;
else
V_2 -> V_25 -> type = V_35 ;
if ( ! V_2 -> V_45 ) {
V_2 -> V_13 = V_6 -> V_60 ;
} else {
F_11 ( V_2 ) ;
V_2 -> V_13 = V_6 -> V_60 ;
F_13 ( V_2 ) ;
}
V_16:
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
void F_18 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_19 ( V_63 , struct V_1 , V_64 ) ;
short V_65 ;
V_65 = V_2 -> V_22 . V_23 ;
if ( V_2 -> V_66 )
V_2 -> V_66 ( V_2 -> V_25 ) ;
F_3 ( V_2 ) ;
V_2 -> V_28 = V_38 ;
V_2 -> V_67 ( V_2 -> V_25 ) ;
F_20 ( V_2 ) ;
V_2 -> V_24 ( V_2 -> V_25 , V_65 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_67 ( V_2 -> V_25 ) ;
if ( V_2 -> V_68 )
V_2 -> V_68 ( V_2 -> V_25 ) ;
if ( V_2 -> V_13 == V_26 || V_2 -> V_13 == V_27 )
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_12 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_36 || ! ( V_2 -> V_45 ) ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_28 == V_29 ) {
F_22 ( V_2 -> V_69 , & V_2 -> V_64 ) ;
return 0 ;
}
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_31 )
{
int V_8 = 0 , V_50 ;
short V_45 ;
unsigned long V_32 ;
V_2 -> V_48 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
V_45 = V_2 -> V_45 ;
if ( V_6 -> V_54 . V_55 > V_70 ) {
V_8 = - V_71 ;
goto V_16;
}
if ( V_2 -> V_13 == V_36 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_45 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_37 , V_32 ) ;
if ( V_6 -> V_54 . V_32 && V_6 -> V_54 . V_55 ) {
V_50 = ( V_6 -> V_54 . V_55 < V_70 ) ? ( V_6 -> V_54 . V_55 ) : V_70 ;
memset ( V_2 -> V_22 . V_51 , 0 , V_2 -> V_22 . V_52 ) ;
strncpy ( V_2 -> V_22 . V_51 , V_31 , V_50 ) ;
V_2 -> V_22 . V_52 = V_50 ;
V_2 -> V_53 = 1 ;
if ( V_50 == 0 ) {
memset ( V_2 -> V_22 . V_42 , 0 , V_41 ) ;
V_2 -> V_22 . V_72 = 0 ;
}
} else {
V_2 -> V_53 = 0 ;
V_2 -> V_22 . V_51 [ 0 ] = '\0' ;
V_2 -> V_22 . V_52 = 0 ;
}
F_9 ( & V_2 -> V_37 , V_32 ) ;
if ( V_45 )
F_13 ( V_2 ) ;
V_16:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , union V_5 * V_6 ,
char * V_7 )
{
V_6 -> V_60 = V_2 -> V_13 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
int * V_73 = ( int * ) V_31 ;
int V_74 = ( V_73 [ 0 ] > 0 ) ;
short V_75 = V_2 -> V_76 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_74 )
V_2 -> V_76 = 1 ;
else
V_2 -> V_76 = 0 ;
F_26 ( V_2 -> V_25 , L_1 ,
V_2 -> V_76 ? L_2 : L_3 ) ;
if ( V_2 -> V_13 == V_36 ) {
if ( V_75 == 0 && V_2 -> V_76 ) {
if ( V_2 -> V_68 )
V_2 -> V_68 ( V_2 -> V_25 ) ;
F_27 ( V_2 -> V_25 ) ;
}
if ( V_75 && V_2 -> V_76 == 1 )
F_28 ( V_2 -> V_25 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
F_30 ( V_6 -> V_77 , L_4 , V_78 ) ;
if ( V_2 -> V_79 & V_80 ) {
F_31 ( V_6 -> V_77 , L_5 , V_78 ) ;
if ( V_2 -> V_79 & V_81 )
F_31 ( V_6 -> V_77 , L_6 , V_78 ) ;
} else if ( V_2 -> V_79 & V_81 )
F_31 ( V_6 -> V_77 , L_7 , V_78 ) ;
if ( ( V_2 -> V_28 == V_29 ) ||
( V_2 -> V_28 == V_38 ) )
F_31 ( V_6 -> V_77 , L_8 , V_78 ) ;
else if ( V_2 -> V_28 != V_82 )
F_31 ( V_6 -> V_77 , L_9 , V_78 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
int V_8 = 0 ;
if ( ( ! V_2 -> V_83 ) ||
( ! V_2 -> V_84 ) ||
( ! V_2 -> V_85 ) ||
( ! V_2 -> V_86 ) ) {
F_33 ( L_10 ) ;
return - 1 ;
}
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_87 . V_88 ) {
V_2 -> V_89 = V_90 ;
goto exit;
}
switch ( V_6 -> V_87 . V_32 & V_91 ) {
case V_92 :
V_2 -> V_89 = V_93 ;
break;
case V_94 :
V_2 -> V_89 = V_93 | V_95 ;
break;
case V_96 :
V_2 -> V_89 = V_90 ;
break;
default:
V_8 = - V_49 ;
goto exit;
}
if ( V_6 -> V_87 . V_32 & V_97 ) {
V_2 -> V_98 = V_6 -> V_87 . V_58 / 1000 ;
F_33 ( L_11 , V_2 -> V_98 ) ;
}
if ( V_6 -> V_87 . V_32 & V_99 ) {
V_8 = - V_15 ;
goto exit;
}
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_30 , union V_5 * V_6 ,
char * V_31 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_89 == V_90 ) {
V_6 -> V_87 . V_88 = 1 ;
goto exit;
}
V_6 -> V_87 . V_88 = 0 ;
V_6 -> V_87 . V_32 = V_97 ;
V_6 -> V_87 . V_58 = V_2 -> V_98 * 1000 ;
if ( V_2 -> V_89 & V_95 )
V_6 -> V_87 . V_32 |= V_94 ;
else
V_6 -> V_87 . V_32 |= V_92 ;
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
