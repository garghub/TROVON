int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
const char * V_7 ;
T_2 V_8 = V_3 ;
T_2 V_9 = V_4 ;
T_3 V_10 = V_5 ;
T_2 V_11 = V_6 ;
F_2 ( V_2 -> V_12 , & V_7 , & V_2 -> type ,
& V_8 , & V_9 , & V_10 , & V_11 , & V_2 -> V_13 ) ;
if ( V_7 == NULL )
return - V_14 ;
V_2 -> V_15 = V_8 ;
V_2 -> V_16 = V_9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_17 = V_11 ;
V_2 -> V_18 [ 0 ] = V_2 -> V_18 [ 1 ] = 0 ;
F_3 ( V_2 -> V_7 , V_7 , sizeof( V_2 -> V_7 ) ) ;
return 0 ;
}
void F_4 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
F_5 ( V_20 , V_24 ) ;
V_20 -> V_13 |= V_25 ;
V_20 -> V_26 = V_22 -> V_27 . V_28 -> V_26 ;
V_20 -> V_27 = & V_22 -> V_27 ;
F_6 ( V_20 , V_22 ) ;
F_7 ( V_22 , V_20 ) ;
snprintf ( V_20 -> V_7 , sizeof( V_20 -> V_7 ) , L_1 ,
V_22 -> V_27 . V_28 -> V_7 , F_8 ( V_22 -> V_29 ) ,
V_22 -> V_30 ) ;
}
struct V_19 * F_9 ( struct V_31 * V_32 ,
struct V_33 * V_29 , struct V_34 * V_35 ,
const unsigned short * V_36 )
{
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 ;
F_10 ( ! V_32 ) ;
F_11 ( V_37 L_2 , V_35 -> type ) ;
if ( V_35 -> V_30 == 0 && V_36 )
V_22 = F_12 ( V_29 , V_35 , V_36 ,
NULL ) ;
else
V_22 = F_13 ( V_29 , V_35 ) ;
if ( V_22 == NULL || V_22 -> V_27 . V_28 == NULL )
goto error;
if ( ! F_14 ( V_22 -> V_27 . V_28 -> V_26 ) )
goto error;
V_20 = F_15 ( V_22 ) ;
if ( F_16 ( V_32 , V_20 ) )
V_20 = NULL ;
F_17 ( V_22 -> V_27 . V_28 -> V_26 ) ;
error:
if ( V_22 && V_20 == NULL )
F_18 ( V_22 ) ;
return V_20 ;
}
struct V_19 * F_19 ( struct V_31 * V_32 ,
struct V_33 * V_29 , const char * V_38 ,
T_4 V_30 , const unsigned short * V_36 )
{
struct V_34 V_35 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
F_3 ( V_35 . type , V_38 , sizeof( V_35 . type ) ) ;
V_35 . V_30 = V_30 ;
return F_9 ( V_32 , V_29 , & V_35 , V_36 ) ;
}
unsigned short F_20 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_21 ( V_20 ) ;
return V_22 ? V_22 -> V_30 : V_39 ;
}
const unsigned short * F_22 ( enum V_40 type )
{
static const unsigned short V_41 [] = {
#if F_23 ( V_42 )
0x10 ,
#endif
0x60 ,
V_39
} ;
static const unsigned short V_43 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_39
} ;
static const unsigned short V_44 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_39
} ;
switch ( type ) {
case V_45 :
return V_41 ;
case V_46 :
return V_43 ;
case V_47 :
return V_44 ;
case V_48 :
return V_44 + 4 ;
}
return NULL ;
}
void F_24 ( struct V_19 * V_20 , struct V_49 * V_50 ,
const struct V_23 * V_24 )
{
F_5 ( V_20 , V_24 ) ;
V_20 -> V_13 |= V_51 ;
V_20 -> V_26 = V_50 -> V_27 . V_28 -> V_26 ;
V_20 -> V_27 = & V_50 -> V_27 ;
F_6 ( V_20 , V_50 ) ;
F_25 ( V_50 , V_20 ) ;
F_3 ( V_20 -> V_7 , V_50 -> V_27 . V_28 -> V_7 , sizeof( V_20 -> V_7 ) ) ;
}
struct V_19 * F_26 ( struct V_31 * V_32 ,
struct V_52 * V_53 , struct V_54 * V_35 )
{
struct V_19 * V_20 = NULL ;
struct V_49 * V_50 = NULL ;
F_10 ( ! V_32 ) ;
if ( V_35 -> V_55 [ 0 ] )
F_11 ( V_35 -> V_55 ) ;
V_50 = F_27 ( V_53 , V_35 ) ;
if ( V_50 == NULL || V_50 -> V_27 . V_28 == NULL )
goto error;
if ( ! F_14 ( V_50 -> V_27 . V_28 -> V_26 ) )
goto error;
V_20 = F_28 ( V_50 ) ;
if ( F_16 ( V_32 , V_20 ) )
V_20 = NULL ;
F_17 ( V_50 -> V_27 . V_28 -> V_26 ) ;
error:
if ( V_50 && V_20 == NULL )
F_29 ( V_50 ) ;
return V_20 ;
}
static unsigned int F_30 ( unsigned int V_56 , unsigned int V_8 ,
unsigned int V_9 , unsigned int V_57 )
{
unsigned int V_58 = ~ ( ( 1 << V_57 ) - 1 ) ;
V_56 = F_31 ( V_56 , ( V_8 + ~ V_58 ) & V_58 , V_9 & V_58 ) ;
if ( V_57 )
V_56 = ( V_56 + ( 1 << ( V_57 - 1 ) ) ) & V_58 ;
return V_56 ;
}
void F_32 ( T_5 * V_59 , unsigned int V_60 , unsigned int V_61 ,
unsigned int V_62 ,
T_5 * V_63 , unsigned int V_64 , unsigned int V_65 ,
unsigned int V_66 , unsigned int V_67 )
{
* V_59 = F_30 ( * V_59 , V_60 , V_61 , V_62 ) ;
* V_63 = F_30 ( * V_63 , V_64 , V_65 , V_66 ) ;
if ( ! V_67 )
return;
V_62 = F_33 ( * V_59 ) ;
V_66 = F_33 ( * V_63 ) ;
if ( V_62 + V_66 < V_67 ) {
unsigned int V_68 = F_34 ( V_61 ^ ( V_60 - 1 ) ) ;
unsigned int V_69 = F_34 ( V_65 ^ ( V_64 - 1 ) ) ;
do {
if ( V_66 >= V_69 ||
( V_62 <= V_66 && V_62 < V_68 ) ) {
* V_59 = F_30 ( * V_59 , V_60 , V_61 , V_62 + 1 ) ;
V_62 = F_33 ( * V_59 ) ;
} else {
* V_63 = F_30 ( * V_63 , V_64 , V_65 , V_66 + 1 ) ;
V_66 = F_33 ( * V_63 ) ;
}
} while ( V_66 + V_62 < V_67 );
}
}
const struct V_70 * F_35 (
const struct V_71 * V_72 ,
T_1 V_73 , T_1 V_74 )
{
int V_75 ;
T_5 error , V_76 = V_77 ;
const struct V_70 * V_78 , * V_79 = NULL ;
if ( ! V_72 )
return V_79 ;
for ( V_75 = 0 , V_78 = V_72 -> V_80 ; V_75 < V_72 -> V_81 ; V_75 ++ , V_78 ++ ) {
error = abs ( V_78 -> V_73 - V_73 ) + abs ( V_78 -> V_74 - V_74 ) ;
if ( error < V_76 ) {
V_76 = error ;
V_79 = V_78 ;
}
if ( ! error )
break;
}
return V_79 ;
}
void F_36 ( struct V_82 * V_83 )
{
struct V_84 V_85 ;
F_37 ( & V_85 ) ;
V_83 -> V_86 = V_85 . V_86 ;
V_83 -> V_87 = V_85 . V_88 / V_89 ;
}
