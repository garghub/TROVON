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
if ( V_20 [ 0 ] == NULL ) {
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
if ( V_17 -> V_22 == NULL )
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
while ( ( V_32 -> V_18 != - 1 ) && ( V_31 == NULL ) ) {
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
short V_37 = 0 ;
int * V_38 = V_13 -> V_38 ;
int V_39 ;
char V_40 [ 32 ] ;
char * V_41 ;
struct V_12 * V_42 = V_13 -> V_22 ;
if ( V_42 == NULL )
return - V_43 ;
if ( V_35 == V_44 ) {
if ( V_34 < V_42 -> V_45 . V_46 . V_47 || V_34 > V_42 -> V_45 . V_46 . V_48 )
return - V_49 ;
V_42 -> V_45 . V_46 . V_50 = V_34 ;
return 0 ;
}
if ( V_35 == V_27 ) {
V_36 = V_42 -> V_45 . V_46 . V_50 ;
V_37 = - V_51 ;
} else {
if ( V_35 == V_52 )
V_36 = V_34 ;
else
V_36 = V_42 -> V_45 . V_46 . V_2 ;
if ( V_35 == V_53 )
V_36 += V_34 ;
else if ( V_35 == V_54 )
V_36 -= V_34 ;
if ( V_36 < V_42 -> V_45 . V_46 . V_47 || V_36 > V_42 -> V_45 . V_46 . V_48 )
return - V_49 ;
}
V_42 -> V_45 . V_46 . V_2 = V_36 ;
if ( V_13 -> V_23 == V_26 && V_38 != NULL ) {
* V_38 = F_11 ( V_36 ) ;
return V_37 ;
}
if ( V_38 != NULL )
* V_38 = V_36 ;
if ( V_13 -> V_18 == V_55 ) {
V_56 = V_57 [ V_36 ] ;
return V_37 ;
}
if ( V_42 -> V_45 . V_46 . V_58 != 0 )
V_36 *= V_42 -> V_45 . V_46 . V_58 ;
V_36 += V_42 -> V_45 . V_46 . V_59 ;
if ( V_13 -> V_18 < V_60 || V_61 == NULL )
return V_37 ;
if ( V_61 -> V_62 != NULL ) {
int V_63 = V_61 -> V_62 ( V_13 ) ;
return ( V_63 != 0 ) ? V_63 : V_37 ;
}
if ( ! V_42 -> V_45 . V_46 . V_64 )
return V_37 ;
if ( V_13 -> V_18 == V_65 )
V_41 = V_66 ;
else
V_41 = V_40 ;
if ( ! V_42 -> V_45 . V_46 . V_67 )
V_39 = sprintf ( V_41 , V_42 -> V_45 . V_46 . V_64 , ( int ) V_36 ) ;
else
V_39 = sprintf ( V_41 ,
V_42 -> V_45 . V_46 . V_64 , V_42 -> V_45 . V_46 . V_67 [ V_36 ] ) ;
F_12 ( L_11 , V_41 ) ;
return V_37 ;
}
int F_4 ( const char * V_68 , struct V_16 * V_13 , int V_69 )
{
struct V_12 * V_42 = V_13 -> V_22 ;
if ( V_42 == NULL )
return - V_43 ;
if ( V_69 > V_70 )
return - V_71 ;
if ( ! V_69 ) {
if ( ! V_42 -> V_45 . V_72 . V_50 )
return 0 ;
if ( ! V_13 -> V_38 )
V_13 -> V_38 = V_42 -> V_45 . V_72 . V_50 ;
if ( V_13 -> V_38 != V_42 -> V_45 . V_72 . V_50 )
strcpy ( ( char * ) V_13 -> V_38 , V_42 -> V_45 . V_72 . V_50 ) ;
return - V_51 ;
} else if ( V_13 -> V_38 )
strcpy ( ( char * ) V_13 -> V_38 , V_68 ) ;
else
return - V_71 ;
return 0 ;
}
int F_13 ( const char * V_34 , const int V_73 , const int V_35 )
{
T_1 * V_41 ;
short V_74 = V_75 [ V_73 ] . V_74 ;
if ( V_35 & 1 ) {
for ( V_41 = ( T_1 * ) V_75 [ 3 ] . V_2 ; * V_41 ; V_41 ++ )
V_76 [ * V_41 ] &= ~ V_74 ;
}
V_41 = ( T_1 * ) V_34 ;
if ( ! V_41 )
V_41 = V_75 [ V_73 ] . V_2 ;
else {
for (; * V_41 ; V_41 ++ ) {
if ( * V_41 < V_77 )
break;
if ( V_74 < V_7 ) {
if ( ! ( V_76 [ * V_41 ] & V_7 ) )
break;
} else if ( V_76 [ * V_41 ] & V_78 )
break;
}
if ( * V_41 )
return - V_79 ;
V_41 = ( T_1 * ) V_34 ;
}
if ( V_35 & 2 ) {
for (; * V_41 ; V_41 ++ )
if ( * V_41 > V_77 )
V_76 [ * V_41 ] |= V_74 ;
} else {
for (; * V_41 ; V_41 ++ )
if ( * V_41 > V_77 )
V_76 [ * V_41 ] &= ~ V_74 ;
}
return 0 ;
}
char * F_14 ( char * V_72 )
{
char * V_80 ;
if ( V_72 == NULL )
return NULL ;
for ( V_80 = V_72 ; * V_80 ; V_80 ++ )
* V_80 = tolower ( * V_80 ) ;
return V_72 ;
}
char * F_15 ( char * V_81 , char * V_82 )
{
int V_36 = 0 ;
V_36 = F_16 ( F_17 ( V_81 ) , & V_81 , 10 ) ;
if ( * V_81 == ',' )
V_81 ++ ;
* V_82 = ( T_1 ) V_36 ;
return V_81 ;
}
