int F_1 ( char * V_1 )
{
int V_2 = 0 ;
if ( ! strcmp ( V_1 , L_1 ) )
V_2 = V_3 ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 = V_4 ;
else if ( ! strcmp ( V_1 , L_3 ) )
V_2 = V_5 ;
else if ( ! strcmp ( V_1 , L_4 ) )
V_2 = V_6 ;
else if ( ! strcmp ( V_1 , L_5 ) )
V_2 = V_7 ;
else if ( ! strcmp ( V_1 , L_6 ) )
V_2 = V_8 ;
else if ( ! strcmp ( V_1 , L_7 ) )
V_2 = V_9 ;
else if ( ! strcmp ( V_1 , L_8 ) )
V_2 = V_10 ;
else if ( ! strcmp ( V_1 , L_9 ) )
V_2 = V_11 ;
return V_2 ;
}
void F_2 ( struct V_12 * V_13 )
{
static char V_14 [ 2 ] = L_10 ;
int V_15 ;
struct V_16 * V_17 ;
F_3 ( ! V_13 || V_13 -> V_18 < 0 || V_13 -> V_18 >= V_19 ) ;
if ( ! V_20 [ 0 ] ) {
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_17 = & V_21 [ V_15 ] ;
V_20 [ V_17 -> V_18 ] = V_17 ;
V_17 -> V_22 = NULL ;
}
}
V_17 = V_20 [ V_13 -> V_18 ] ;
if ( V_17 -> V_22 != NULL )
return;
V_17 -> V_22 = V_13 ;
switch ( V_17 -> V_23 ) {
case V_24 :
F_4 ( V_14 , V_17 , 0 ) ;
break;
case V_25 :
case V_26 :
F_5 ( 0 , V_17 , V_27 ) ;
break;
default:
break;
}
}
void F_6 ( enum V_28 V_18 )
{
struct V_16 * V_17 ;
F_3 ( V_18 < 0 || V_18 >= V_19 ) ;
V_17 = V_20 [ V_18 ] ;
V_17 -> V_22 = NULL ;
}
struct V_16 * F_7 ( enum V_28 V_18 )
{
struct V_16 * V_17 ;
if ( V_18 < 0 || V_18 >= V_19 )
return NULL ;
V_17 = V_20 [ V_18 ] ;
if ( ! V_17 -> V_22 )
return NULL ;
return V_17 ;
}
struct V_16 * F_8 ( const char * V_29 )
{
int V_15 ;
if ( ! V_29 )
return NULL ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
if ( strcmp ( V_29 , V_20 [ V_15 ] -> V_29 ) == 0 )
return V_20 [ V_15 ] ;
}
return NULL ;
}
struct V_12 * F_9 ( enum V_28 V_18 )
{
F_3 ( V_18 < 0 || V_18 >= V_19 ) ;
F_3 ( ! V_20 [ V_18 ] ) ;
return V_20 [ V_18 ] -> V_22 ;
}
struct V_30 * F_10 ( enum V_28 V_18 )
{
struct V_30 * V_31 = NULL ;
struct V_30 * V_32 ;
V_32 = V_33 ;
while ( ( V_32 -> V_18 != - 1 ) && ( ! V_31 ) ) {
if ( V_32 -> V_18 == V_18 )
V_31 = V_32 ;
else
V_32 ++ ;
}
return V_31 ;
}
int F_5 ( int V_34 , struct V_16 * V_13 , int V_35 )
{
int V_36 ;
int * V_37 = V_13 -> V_37 ;
int V_38 ;
char V_39 [ 32 ] ;
char * V_40 ;
struct V_12 * V_41 = V_13 -> V_22 ;
if ( ! V_41 )
return - V_42 ;
V_36 = V_41 -> V_43 . V_44 . V_2 ;
switch ( V_35 ) {
case V_45 :
if ( V_34 < V_41 -> V_43 . V_44 . V_46 || V_34 > V_41 -> V_43 . V_44 . V_47 )
return - V_48 ;
V_41 -> V_43 . V_44 . V_49 = V_34 ;
return 0 ;
case V_27 :
V_36 = V_41 -> V_43 . V_44 . V_49 ;
break;
case V_50 :
V_36 = V_34 ;
break;
case V_51 :
V_36 += V_34 ;
break;
case V_52 :
V_36 -= V_34 ;
break;
}
if ( V_36 < V_41 -> V_43 . V_44 . V_46 || V_36 > V_41 -> V_43 . V_44 . V_47 )
return - V_48 ;
V_41 -> V_43 . V_44 . V_2 = V_36 ;
if ( V_13 -> V_23 == V_26 && V_37 != NULL ) {
* V_37 = F_11 ( V_36 ) ;
return 0 ;
}
if ( V_37 != NULL )
* V_37 = V_36 ;
if ( V_13 -> V_18 == V_53 ) {
V_54 = V_55 [ V_36 ] ;
return 0 ;
}
if ( V_41 -> V_43 . V_44 . V_56 != 0 )
V_36 *= V_41 -> V_43 . V_44 . V_56 ;
V_36 += V_41 -> V_43 . V_44 . V_57 ;
if ( V_13 -> V_18 < V_58 || ! V_59 )
return 0 ;
if ( V_59 -> V_60 )
return V_59 -> V_60 ( V_13 ) ;
if ( ! V_41 -> V_43 . V_44 . V_61 )
return 0 ;
if ( V_13 -> V_18 == V_62 )
V_40 = V_63 ;
else
V_40 = V_39 ;
if ( ! V_41 -> V_43 . V_44 . V_64 )
V_38 = sprintf ( V_40 , V_41 -> V_43 . V_44 . V_61 , ( int ) V_36 ) ;
else
V_38 = sprintf ( V_40 ,
V_41 -> V_43 . V_44 . V_61 , V_41 -> V_43 . V_44 . V_64 [ V_36 ] ) ;
F_12 ( L_11 , V_40 ) ;
return 0 ;
}
int F_4 ( const char * V_65 , struct V_16 * V_13 , int V_66 )
{
struct V_12 * V_41 = V_13 -> V_22 ;
if ( ! V_41 )
return - V_42 ;
if ( V_66 > V_67 )
return - V_68 ;
if ( ! V_66 ) {
if ( ! V_41 -> V_43 . V_69 . V_49 )
return 0 ;
if ( ! V_13 -> V_37 )
V_13 -> V_37 = V_41 -> V_43 . V_69 . V_49 ;
if ( V_13 -> V_37 != V_41 -> V_43 . V_69 . V_49 )
strcpy ( ( char * ) V_13 -> V_37 , V_41 -> V_43 . V_69 . V_49 ) ;
return - V_70 ;
} else if ( V_13 -> V_37 )
strcpy ( ( char * ) V_13 -> V_37 , V_65 ) ;
else
return - V_68 ;
return 0 ;
}
int F_13 ( const char * V_34 , const int V_71 , const int V_35 )
{
T_1 * V_40 ;
short V_72 = V_73 [ V_71 ] . V_72 ;
if ( V_35 & 1 ) {
for ( V_40 = ( T_1 * ) V_73 [ 3 ] . V_2 ; * V_40 ; V_40 ++ )
V_74 [ * V_40 ] &= ~ V_72 ;
}
V_40 = ( T_1 * ) V_34 ;
if ( ! V_40 )
V_40 = V_73 [ V_71 ] . V_2 ;
else {
for (; * V_40 ; V_40 ++ ) {
if ( * V_40 < V_75 )
break;
if ( V_72 < V_7 ) {
if ( ! ( V_74 [ * V_40 ] & V_7 ) )
break;
} else if ( V_74 [ * V_40 ] & V_76 )
break;
}
if ( * V_40 )
return - V_77 ;
V_40 = ( T_1 * ) V_34 ;
}
if ( V_35 & 2 ) {
for (; * V_40 ; V_40 ++ )
if ( * V_40 > V_75 )
V_74 [ * V_40 ] |= V_72 ;
} else {
for (; * V_40 ; V_40 ++ )
if ( * V_40 > V_75 )
V_74 [ * V_40 ] &= ~ V_72 ;
}
return 0 ;
}
char * F_14 ( char * V_69 )
{
char * V_78 ;
if ( ! V_69 )
return NULL ;
for ( V_78 = V_69 ; * V_78 ; V_78 ++ )
* V_78 = tolower ( * V_78 ) ;
return V_69 ;
}
char * F_15 ( char * V_79 , char * V_80 )
{
int V_36 ;
V_36 = F_16 ( F_17 ( V_79 ) , & V_79 , 10 ) ;
if ( * V_79 == ',' )
V_79 ++ ;
* V_80 = ( T_1 ) V_36 ;
return V_79 ;
}
