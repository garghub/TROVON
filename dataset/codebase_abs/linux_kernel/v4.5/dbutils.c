T_1
F_1 ( char * V_1 ,
struct V_2 * V_3 )
{
T_2 V_4 ;
if ( ! V_1 || V_1 [ 0 ] == 0 ) {
return ( V_5 ) ;
}
for ( V_4 = 0 ; V_3 [ V_4 ] . V_6 ; V_4 ++ ) {
if ( strstr ( V_3 [ V_4 ] . V_6 , V_1 ) ==
V_3 [ V_4 ] . V_6 ) {
return ( V_4 ) ;
}
}
return ( V_5 ) ;
}
void F_2 ( T_2 V_7 )
{
V_8 = ( V_9 ) V_7 ;
if ( ( V_7 & V_10 ) &&
V_11 ) {
V_12 = V_13 ;
} else {
V_12 = V_14 ;
}
}
void F_3 ( union V_15 * V_16 , T_2 V_17 )
{
T_2 V_4 ;
if ( ! V_16 ) {
F_4 ( L_1 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
F_4 ( L_2 ) ;
}
switch ( V_16 -> type ) {
case V_18 :
F_4 ( L_3 ) ;
break;
case V_19 :
F_4 ( L_4 ,
F_5 ( V_16 -> integer . V_20 ) ) ;
break;
case V_21 :
F_4 ( L_5 ,
V_16 -> string . V_22 ) ;
F_6 ( V_16 -> string . V_23 , V_24 ) ;
F_4 ( L_6 ) ;
break;
case V_25 :
F_4 ( L_7 ,
V_16 -> V_26 . V_22 ) ;
if ( V_16 -> V_26 . V_22 ) {
if ( V_16 -> V_26 . V_22 > 16 ) {
F_4 ( L_6 ) ;
}
F_7 ( F_8
( V_9 ,
V_16 -> V_26 . V_23 ) ,
V_16 -> V_26 . V_22 ,
V_27 , V_28 ) ;
} else {
F_4 ( L_6 ) ;
}
break;
case V_29 :
F_4 ( L_8 ,
V_16 -> V_30 . V_31 ) ;
for ( V_4 = 0 ; V_4 < V_16 -> V_30 . V_31 ; V_4 ++ ) {
F_3 ( & V_16 -> V_30 .
V_32 [ V_4 ] , V_17 + 1 ) ;
}
break;
case V_33 :
F_4 ( L_9 ) ;
F_9 ( V_16 -> V_34 . V_35 ,
NULL ) ;
break;
case V_36 :
F_4 ( L_10 ) ;
break;
case V_37 :
F_4 ( L_11 ) ;
break;
default:
F_4 ( L_12 , V_16 -> type ) ;
break;
}
}
void F_10 ( char * V_6 )
{
if ( ! V_6 ) {
return;
}
F_11 ( V_6 ) ;
if ( * V_6 == '/' ) {
* V_6 = '\\' ;
}
if ( F_12 ( * V_6 ) ) {
V_6 ++ ;
}
while ( * V_6 ) {
if ( ( * V_6 == '/' ) || ( * V_6 == '\\' ) ) {
* V_6 = '.' ;
}
V_6 ++ ;
}
}
struct V_38 * F_13 ( char * V_6 )
{
char * V_39 ;
T_3 V_40 ;
struct V_38 * V_41 = NULL ;
F_10 ( V_6 ) ;
V_40 = F_14 ( V_6 , & V_39 ) ;
if ( F_15 ( V_40 ) ) {
F_4 ( L_13 , V_6 ) ;
return ( NULL ) ;
}
V_40 = F_16 ( NULL , V_39 , V_18 ,
V_42 ,
V_43 | V_44 ,
NULL , & V_41 ) ;
if ( F_15 ( V_40 ) ) {
F_4 ( L_14 ,
V_6 , F_17 ( V_40 ) ) ;
}
F_18 ( V_39 ) ;
return ( V_41 ) ;
}
void F_19 ( T_2 V_20 , char * V_26 )
{
int V_4 ;
if ( V_20 == 0 ) {
strcpy ( V_26 , L_15 ) ;
return;
}
V_26 [ 8 ] = '\0' ;
for ( V_4 = 7 ; V_4 >= 0 ; V_4 -- ) {
V_26 [ V_4 ] = V_45 [ V_20 & 0x0F ] ;
V_20 = V_20 >> 4 ;
}
}
T_3 F_20 ( union V_46 * V_47 )
{
union V_46 * V_48 = V_47 ;
union V_46 * V_49 ;
union V_46 * V_50 ;
union V_46 * V_51 ;
T_3 V_40 = V_52 ;
T_2 V_53 ;
struct V_54 * V_55 ;
F_21 () ;
F_4 ( L_16 ) ;
while ( V_48 ) {
if ( V_48 -> V_56 . V_57 == V_58 ) {
V_49 = V_48 ;
V_55 =
F_22 ( 0 , NULL , NULL , NULL ) ;
if ( ! V_55 ) {
return ( V_59 ) ;
}
V_55 -> V_60 . V_61 =
V_55 -> V_60 . V_62 =
V_49 -> V_63 . V_64 ;
V_55 -> V_60 . V_65 =
V_55 -> V_60 . V_66 =
V_49 -> V_63 . V_64 + V_49 -> V_63 . V_22 ;
V_55 -> V_60 . V_67 = V_48 ;
V_55 -> V_68 =
V_69 ;
V_55 -> V_70 = V_71 ;
V_40 = F_23 ( V_55 ) ;
V_53 =
( V_49 -> V_56 . V_20 . V_72 ) -> V_56 . V_73 + 1 ;
V_51 = ( V_49 -> V_56 . V_20 . V_72 ) -> V_56 . V_74 ;
V_50 = V_51 ;
while ( V_50 ) {
V_50 -> V_56 . V_73 += V_53 ;
V_50 =
F_24 ( V_51 , V_50 ) ;
}
}
if ( V_48 -> V_56 . V_57 == V_75 ) {
}
if ( F_15 ( V_40 ) ) {
break;
}
V_48 = F_24 ( V_47 , V_48 ) ;
}
return ( V_40 ) ;
}
void F_25 ( T_2 V_76 )
{
F_4 ( L_17 , V_76 ) ;
V_12 |= V_77 ;
F_7 ( F_26 ( V_76 ) , 64 , V_27 ,
V_78 ) ;
}
