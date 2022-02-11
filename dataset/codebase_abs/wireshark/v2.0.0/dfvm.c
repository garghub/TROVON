T_1 *
F_1 ( T_2 V_1 )
{
T_1 * V_2 ;
V_2 = F_2 ( T_1 , 1 ) ;
V_2 -> V_1 = V_1 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
return V_2 ;
}
static void
F_3 ( T_3 * V_7 )
{
switch ( V_7 -> type ) {
case V_8 :
F_4 ( V_7 -> V_9 . V_10 ) ;
break;
case V_11 :
F_5 ( V_7 -> V_9 . V_12 ) ;
break;
default:
;
}
F_6 ( V_7 ) ;
}
void
F_7 ( T_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_3 ( V_2 -> V_3 ) ;
}
if ( V_2 -> V_4 ) {
F_3 ( V_2 -> V_4 ) ;
}
if ( V_2 -> V_5 ) {
F_3 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_6 ) {
F_3 ( V_2 -> V_6 ) ;
}
F_6 ( V_2 ) ;
}
T_3 *
F_8 ( T_4 type )
{
T_3 * V_7 ;
V_7 = F_2 ( T_3 , 1 ) ;
V_7 -> type = type ;
return V_7 ;
}
void
F_9 ( T_5 * V_13 , T_6 * V_14 )
{
int V_15 , V_16 ;
T_1 * V_2 ;
T_3 * V_3 ;
T_3 * V_4 ;
T_3 * V_5 ;
T_3 * V_6 ;
char * V_17 ;
T_7 * V_18 ;
T_8 * V_19 ;
fprintf ( V_13 , L_1 ) ;
V_16 = V_14 -> V_20 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_2 = ( T_1 * ) F_10 ( V_14 -> V_20 , V_15 ) ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_1 ) {
case V_22 :
V_17 = F_11 ( V_3 -> V_9 . V_10 ,
V_23 , V_24 , NULL ) ;
fprintf ( V_13 , L_2 ,
V_15 , V_17 ,
F_12 ( V_3 -> V_9 . V_10 ) ,
V_4 -> V_9 . V_25 ) ;
F_6 ( V_17 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case RETURN :
case V_40 :
case V_41 :
default:
F_13 () ;
break;
}
}
fprintf ( V_13 , L_3 ) ;
V_16 = V_14 -> V_42 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_2 = ( T_1 * ) F_10 ( V_14 -> V_42 , V_15 ) ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
V_5 = V_2 -> V_5 ;
V_6 = V_2 -> V_6 ;
switch ( V_2 -> V_1 ) {
case V_26 :
fprintf ( V_13 , L_4 ,
V_15 , V_3 -> V_9 . V_43 -> V_44 ) ;
break;
case V_27 :
fprintf ( V_13 , L_5 ,
V_15 , V_3 -> V_9 . V_43 -> V_44 ,
V_4 -> V_9 . V_25 ) ;
break;
case V_28 :
fprintf ( V_13 , L_6 ,
V_15 , V_3 -> V_9 . V_45 -> V_46 ) ;
if ( V_5 ) {
fprintf ( V_13 , L_7 , V_5 -> V_9 . V_25 ) ;
}
if ( V_6 ) {
fprintf ( V_13 , L_8 , V_6 -> V_9 . V_25 ) ;
}
fprintf ( V_13 , L_9 , V_4 -> V_9 . V_25 ) ;
break;
case V_22 :
F_13 () ;
break;
case V_29 :
V_5 = V_2 -> V_5 ;
fprintf ( V_13 , L_10 ,
V_15 ,
V_3 -> V_9 . V_25 ) ;
for ( V_18 = V_5 -> V_9 . V_12 -> V_18 ;
V_18 != NULL ;
V_18 = V_18 -> V_47 ) {
V_19 = ( T_8 * ) V_18 -> V_48 ;
switch ( V_19 -> V_49 ) {
case V_50 :
fprintf ( V_13 , L_11 ) ;
break;
case V_51 :
fprintf ( V_13 , L_12 ,
V_19 -> V_52 ,
V_19 -> V_16 ) ;
break;
case V_53 :
fprintf ( V_13 , L_13 ,
V_19 -> V_52 ,
V_19 -> V_54 ) ;
break;
case V_55 :
fprintf ( V_13 , L_14 ,
V_19 -> V_52 ) ;
break;
}
if ( V_18 -> V_47 != NULL )
fprintf ( V_13 , L_15 ) ;
}
fprintf ( V_13 , L_16 ,
V_4 -> V_9 . V_25 ) ;
break;
case V_30 :
fprintf ( V_13 , L_17 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_31 :
fprintf ( V_13 , L_18 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_32 :
fprintf ( V_13 , L_19 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_33 :
fprintf ( V_13 , L_20 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_34 :
fprintf ( V_13 , L_21 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_35 :
fprintf ( V_13 , L_22 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_36 :
fprintf ( V_13 , L_23 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_37 :
fprintf ( V_13 , L_24 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_38 :
fprintf ( V_13 , L_25 ,
V_15 , V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_39 :
fprintf ( V_13 , L_26 , V_15 ) ;
break;
case RETURN :
fprintf ( V_13 , L_27 , V_15 ) ;
break;
case V_40 :
fprintf ( V_13 , L_28 ,
V_15 , V_3 -> V_9 . V_25 ) ;
break;
case V_41 :
fprintf ( V_13 , L_29 ,
V_15 , V_3 -> V_9 . V_25 ) ;
break;
default:
F_13 () ;
break;
}
}
}
static T_9
F_14 ( T_6 * V_14 , T_10 * V_56 , T_11 * V_43 , int V_57 )
{
T_12 * V_58 ;
T_13 * V_59 ;
int V_60 , V_21 ;
T_14 * V_61 = NULL ;
T_9 V_62 = FALSE ;
if ( V_14 -> V_63 [ V_57 ] ) {
if ( V_14 -> V_64 [ V_57 ] ) {
return TRUE ;
}
else {
return FALSE ;
}
}
V_14 -> V_63 [ V_57 ] = TRUE ;
while ( V_43 ) {
V_58 = F_15 ( V_56 , V_43 -> V_15 ) ;
if ( ( V_58 == NULL ) || ( F_16 ( V_58 ) == 0 ) ) {
V_43 = V_43 -> V_65 ;
continue;
}
else {
V_62 = TRUE ;
}
V_21 = V_58 -> V_21 ;
for ( V_60 = 0 ; V_60 < V_21 ; V_60 ++ ) {
V_59 = ( T_13 * ) F_10 ( V_58 , V_60 ) ;
V_61 = F_17 ( V_61 , & V_59 -> V_9 ) ;
}
V_43 = V_43 -> V_65 ;
}
if ( ! V_62 ) {
return FALSE ;
}
V_14 -> V_64 [ V_57 ] = V_61 ;
return TRUE ;
}
static T_9
F_18 ( T_6 * V_14 , T_15 * V_66 , int V_57 )
{
V_14 -> V_64 [ V_57 ] = F_19 ( NULL , V_66 ) ;
return TRUE ;
}
static T_9
F_20 ( T_6 * V_14 , T_16 V_67 , int V_68 , int V_69 )
{
T_14 * V_70 , * V_71 ;
V_70 = V_14 -> V_64 [ V_68 ] ;
while ( V_70 ) {
V_71 = V_14 -> V_64 [ V_69 ] ;
while ( V_71 ) {
if ( V_67 ( ( T_15 * ) V_70 -> V_48 , ( T_15 * ) V_71 -> V_48 ) ) {
return TRUE ;
}
V_71 = F_21 ( V_71 ) ;
}
V_70 = F_21 ( V_70 ) ;
}
return FALSE ;
}
static void
F_22 ( T_6 * V_14 )
{
T_17 V_60 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_72 ; V_60 ++ ) {
V_14 -> V_63 [ V_60 ] = FALSE ;
if ( V_14 -> V_64 [ V_60 ] ) {
F_23 ( V_14 -> V_64 [ V_60 ] ) ;
V_14 -> V_64 [ V_60 ] = NULL ;
}
}
}
static void
F_24 ( T_6 * V_14 , int V_73 , int V_74 , T_18 * V_75 )
{
T_14 * V_76 , * V_77 ;
T_15 * V_78 , * V_79 ;
V_77 = NULL ;
V_76 = V_14 -> V_64 [ V_73 ] ;
while ( V_76 ) {
V_78 = ( T_15 * ) V_76 -> V_48 ;
V_79 = F_25 ( V_78 , V_75 ) ;
F_26 ( V_79 ) ;
V_77 = F_19 ( V_77 , V_79 ) ;
V_76 = F_21 ( V_76 ) ;
}
V_14 -> V_64 [ V_74 ] = V_77 ;
}
T_9
F_27 ( T_6 * V_14 , T_10 * V_56 )
{
int V_15 , V_16 ;
T_9 V_80 = TRUE ;
T_1 * V_2 ;
T_3 * V_3 ;
T_3 * V_4 ;
T_3 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_11 * V_43 ;
T_14 * V_81 ;
T_14 * V_82 ;
F_26 ( V_56 ) ;
V_16 = V_14 -> V_42 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_83:
V_2 = ( T_1 * ) F_10 ( V_14 -> V_42 , V_15 ) ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_1 ) {
case V_26 :
V_43 = V_3 -> V_9 . V_43 ;
while( V_43 ) {
V_80 = F_28 ( V_56 ,
V_43 -> V_15 ) ;
if ( V_80 ) {
break;
}
else {
V_43 = V_43 -> V_65 ;
}
}
break;
case V_27 :
V_80 = F_14 ( V_14 , V_56 ,
V_3 -> V_9 . V_43 , V_4 -> V_9 . V_25 ) ;
break;
case V_28 :
V_5 = V_2 -> V_5 ;
V_6 = V_2 -> V_6 ;
V_81 = NULL ;
V_82 = NULL ;
if ( V_5 ) {
V_81 = V_14 -> V_64 [ V_5 -> V_9 . V_25 ] ;
}
if ( V_6 ) {
V_82 = V_14 -> V_64 [ V_6 -> V_9 . V_25 ] ;
}
V_80 = V_3 -> V_9 . V_45 -> V_84 ( V_81 , V_82 ,
& V_14 -> V_64 [ V_4 -> V_9 . V_25 ] ) ;
break;
case V_29 :
V_5 = V_2 -> V_5 ;
F_24 ( V_14 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ,
V_5 -> V_9 . V_12 ) ;
break;
case V_30 :
V_80 = F_20 ( V_14 , V_85 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_31 :
V_80 = F_20 ( V_14 , V_86 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_32 :
V_80 = F_20 ( V_14 , V_87 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_33 :
V_80 = F_20 ( V_14 , V_88 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_34 :
V_80 = F_20 ( V_14 , V_89 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_35 :
V_80 = F_20 ( V_14 , V_90 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_36 :
V_80 = F_20 ( V_14 , V_91 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_37 :
V_80 = F_20 ( V_14 , V_92 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_38 :
V_80 = F_20 ( V_14 , V_93 ,
V_3 -> V_9 . V_25 , V_4 -> V_9 . V_25 ) ;
break;
case V_39 :
V_80 = ! V_80 ;
break;
case RETURN :
F_22 ( V_14 ) ;
return V_80 ;
case V_40 :
if ( V_80 ) {
V_15 = V_3 -> V_9 . V_25 ;
goto V_83;
}
break;
case V_41 :
if ( ! V_80 ) {
V_15 = V_3 -> V_9 . V_25 ;
goto V_83;
}
break;
case V_22 :
#if 0
accum = put_fvalue(df,
arg1->value.fvalue, arg2->value.numeric);
break;
#endif
default:
F_13 () ;
break;
}
}
F_13 () ;
return FALSE ;
}
void
F_29 ( T_6 * V_14 )
{
int V_15 , V_16 ;
T_1 * V_2 ;
T_3 * V_3 ;
T_3 * V_4 ;
V_16 = V_14 -> V_20 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_2 = ( T_1 * ) F_10 ( V_14 -> V_20 , V_15 ) ;
V_3 = V_2 -> V_3 ;
V_4 = V_2 -> V_4 ;
switch ( V_2 -> V_1 ) {
case V_22 :
F_18 ( V_14 ,
V_3 -> V_9 . V_10 , V_4 -> V_9 . V_25 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case RETURN :
case V_40 :
case V_41 :
default:
F_13 () ;
break;
}
}
return;
}
