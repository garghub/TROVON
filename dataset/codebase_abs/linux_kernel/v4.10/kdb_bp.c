static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
static char * F_3 ( T_1 * V_4 )
{
if ( V_4 -> V_5 < 0 || V_4 -> V_5 > 4 )
return L_1 ;
return V_6 [ V_4 -> V_5 ] ;
}
static int F_4 ( int V_7 , const char * * V_8 , int * V_9 , T_1 * V_4 )
{
int V_10 = * V_9 ;
int V_11 ;
V_4 -> V_12 = 1 ;
if ( ( V_7 + 1 ) != V_10 ) {
if ( strncasecmp ( V_8 [ V_10 ] , L_2 , sizeof( L_2 ) ) == 0 )
V_4 -> V_5 = V_13 ;
else if ( strncasecmp ( V_8 [ V_10 ] , L_3 , sizeof( L_3 ) ) == 0 )
V_4 -> V_5 = V_14 ;
else if ( strncasecmp ( V_8 [ V_10 ] , L_4 , sizeof( L_4 ) ) == 0 )
V_4 -> V_5 = V_15 ;
else
return V_16 ;
V_4 -> V_12 = 1 ;
V_10 ++ ;
if ( ( V_7 + 1 ) != V_10 ) {
unsigned long V_17 ;
V_11 = F_5 ( ( char * ) V_8 [ V_10 ] ,
& V_17 ) ;
if ( V_11 )
return V_11 ;
if ( V_17 > 8 )
return V_18 ;
V_4 -> V_12 = V_17 ;
V_10 ++ ;
}
if ( ( V_7 + 1 ) != V_10 )
return V_16 ;
}
* V_9 = V_10 ;
return 0 ;
}
static int F_6 ( T_1 * V_4 )
{
int V_19 = 1 ;
if ( ! V_4 -> V_20 )
return V_19 ;
if ( ! V_4 -> V_5 )
V_19 = F_7 ( V_4 -> V_21 ) ;
else
V_19 = V_22 . V_23 ( V_4 -> V_21 ,
V_4 -> V_12 ,
V_4 -> V_5 ) ;
if ( V_19 == 0 )
V_4 -> V_20 = 0 ;
return V_19 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_4 )
{
if ( F_9 ( V_24 ) )
F_10 ( L_5 , F_11 ( V_2 ) ) ;
F_1 ( V_2 ) ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = 1 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_19 ;
if ( F_9 ( V_24 ) )
F_10 ( L_6 ,
V_27 , V_4 -> V_20 ) ;
if ( ! F_13 ( V_28 ) )
V_4 -> V_25 = 0 ;
if ( V_4 -> V_20 )
return 1 ;
if ( V_4 -> V_25 || ( V_4 -> V_26 && F_13 ( V_3 ) ) ) {
if ( F_9 ( V_24 ) )
F_10 ( L_7 , V_27 ) ;
F_8 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! V_4 -> V_5 )
V_19 = F_14 ( V_4 -> V_21 ) ;
else
V_19 = V_22 . V_29 ( V_4 -> V_21 ,
V_4 -> V_12 ,
V_4 -> V_5 ) ;
if ( V_19 == 0 ) {
V_4 -> V_20 = 1 ;
} else {
F_10 ( L_8 ,
V_27 , V_4 -> V_21 ) ;
if ( ! V_4 -> V_5 ) {
F_10 ( L_9
L_10
L_11 ) ;
}
return 1 ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
T_1 * V_4 = & V_32 [ V_30 ] ;
if ( F_9 ( V_24 ) ) {
F_10 ( L_12 ,
V_27 , V_30 , V_4 -> V_33 ) ;
}
if ( V_4 -> V_33 )
F_12 ( V_2 , V_4 ) ;
}
}
void F_16 ( void )
{
int V_30 ;
for ( V_30 = V_31 - 1 ; V_30 >= 0 ; V_30 -- ) {
T_1 * V_4 = & V_32 [ V_30 ] ;
if ( F_9 ( V_24 ) ) {
F_10 ( L_12 ,
V_27 , V_30 , V_4 -> V_33 ) ;
}
if ( V_4 -> V_33 )
F_6 ( V_4 ) ;
}
}
static void F_17 ( T_1 * V_4 , int V_30 )
{
F_10 ( L_13 , F_3 ( V_4 ) ) ;
F_10 ( L_14 , V_30 ) ;
F_18 ( V_4 -> V_21 , NULL , V_34 ) ;
if ( V_4 -> V_33 )
F_10 ( L_15 ) ;
else
F_10 ( L_16 ) ;
F_10 ( L_17 ,
V_4 -> V_21 , V_4 -> V_5 , V_4 -> V_20 ) ;
F_10 ( L_18 ) ;
}
static int F_19 ( int V_7 , const char * * V_8 )
{
int V_30 , V_35 ;
T_1 * V_4 , * V_36 ;
int V_11 ;
char * V_37 = NULL ;
long V_38 = 0ul ;
int V_10 ;
T_1 V_39 = { 0 } ;
if ( V_7 == 0 ) {
for ( V_35 = 0 , V_4 = V_32 ; V_35 < V_31 ;
V_35 ++ , V_4 ++ ) {
if ( V_4 -> V_40 )
continue;
F_17 ( V_4 , V_35 ) ;
}
return 0 ;
}
V_10 = 1 ;
V_11 = F_20 ( V_7 , V_8 , & V_10 , & V_39 . V_21 ,
& V_38 , & V_37 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_39 . V_21 )
return V_41 ;
for ( V_35 = 0 , V_4 = V_32 ; V_35 < V_31 ; V_35 ++ , V_4 ++ ) {
if ( V_4 -> V_40 )
break;
}
if ( V_35 == V_31 )
return V_42 ;
if ( strcmp ( V_8 [ 0 ] , L_19 ) == 0 ) {
V_39 . V_5 = V_15 ;
V_11 = F_4 ( V_7 , V_8 , & V_10 , & V_39 ) ;
if ( V_11 )
return V_11 ;
} else {
V_39 . V_5 = V_43 ;
}
for ( V_30 = 0 , V_36 = V_32 ; V_30 < V_31 ;
V_30 ++ , V_36 ++ ) {
if ( ! V_36 -> V_40 &&
V_36 -> V_21 == V_39 . V_21 ) {
F_10 ( L_20
V_44 L_18 , V_39 . V_21 ) ;
return V_45 ;
}
}
V_39 . V_33 = 1 ;
* V_4 = V_39 ;
V_4 -> V_40 = 0 ;
F_17 ( V_4 , V_35 ) ;
return 0 ;
}
static int F_21 ( int V_7 , const char * * V_8 )
{
unsigned long V_46 ;
T_1 * V_4 = NULL ;
int V_47 = V_31 ;
int V_48 = 0 ;
int V_49 = 0 ;
int V_30 ;
int V_11 = 0 ;
int V_50 ;
#define F_22 0
#define F_23 1
#define F_24 2
if ( strcmp ( V_8 [ 0 ] , L_21 ) == 0 )
V_50 = F_23 ;
else if ( strcmp ( V_8 [ 0 ] , L_22 ) == 0 )
V_50 = F_24 ;
else
V_50 = F_22 ;
if ( V_7 != 1 )
return V_16 ;
if ( strcmp ( V_8 [ 1 ] , L_23 ) == 0 ) {
V_47 = 0 ;
V_48 = V_31 ;
} else {
V_11 = F_5 ( V_8 [ 1 ] , & V_46 ) ;
if ( V_11 )
return V_11 ;
if ( V_46 < V_31 ) {
V_4 = & V_32 [ V_46 ] ;
V_47 = V_48 = V_46 ;
V_48 ++ ;
} else {
for ( V_30 = 0 , V_4 = V_32 ; V_30 < V_31 ;
V_30 ++ , V_4 ++ ) {
if ( V_4 -> V_21 == V_46 ) {
V_47 = V_48 = V_30 ;
V_48 ++ ;
break;
}
}
}
}
for ( V_4 = & V_32 [ V_47 ] , V_30 = V_47 ;
V_30 < V_48 ;
V_30 ++ , V_4 ++ ) {
if ( V_4 -> V_40 )
continue;
V_49 ++ ;
switch ( V_50 ) {
case F_22 :
V_4 -> V_33 = 0 ;
F_10 ( L_24
V_51 L_25 ,
V_30 , V_4 -> V_21 ) ;
V_4 -> V_21 = 0 ;
V_4 -> V_40 = 1 ;
break;
case F_23 :
V_4 -> V_33 = 1 ;
F_10 ( L_24
V_51 L_26 ,
V_30 , V_4 -> V_21 ) ;
F_10 ( L_18 ) ;
break;
case F_24 :
if ( ! V_4 -> V_33 )
break;
V_4 -> V_33 = 0 ;
F_10 ( L_24
V_51 L_27 ,
V_30 , V_4 -> V_21 ) ;
break;
}
if ( V_4 -> V_25 && ( V_50 == F_22 || V_50 == F_24 ) ) {
V_4 -> V_25 = 0 ;
F_25 ( V_28 ) ;
}
}
return ( ! V_49 ) ? V_52 : 0 ;
}
static int F_26 ( int V_7 , const char * * V_8 )
{
if ( V_7 != 0 )
return V_16 ;
F_2 ( V_3 ) ;
return V_53 ;
}
void T_2 F_27 ( void )
{
int V_30 ;
T_1 * V_4 ;
memset ( & V_32 , '\0' , sizeof( V_32 ) ) ;
for ( V_30 = 0 , V_4 = V_32 ; V_30 < V_31 ; V_30 ++ , V_4 ++ )
V_4 -> V_40 = 1 ;
F_28 ( L_28 , F_19 , L_29 ,
L_30 , 0 ,
V_54 | V_55 ) ;
F_28 ( L_31 , F_19 , L_29 ,
L_32 , 0 ,
V_54 | V_55 ) ;
if ( V_22 . V_56 & V_57 )
F_28 ( L_19 , F_19 , L_29 ,
L_33 , 0 ,
V_54 | V_55 ) ;
F_28 ( L_34 , F_21 , L_35 ,
L_36 , 0 ,
V_54 ) ;
F_28 ( L_21 , F_21 , L_35 ,
L_37 , 0 ,
V_54 ) ;
F_28 ( L_22 , F_21 , L_35 ,
L_38 , 0 ,
V_54 ) ;
F_28 ( L_39 , F_26 , L_1 ,
L_40 , 1 ,
V_54 | V_55 ) ;
}
