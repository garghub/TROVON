static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned long V_6 = V_7 * 1000 / V_8 ;
return F_2 ( V_5 , V_9 , L_1 , V_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
unsigned long V_6 ;
if ( F_4 ( V_5 , 0 , & V_6 ) )
return - V_11 ;
V_7 = V_6 * V_8 / 1000 ;
return V_10 ;
}
static int F_5 ( void )
{
static unsigned long V_12 ;
unsigned long V_13 , V_14 ;
long V_15 ;
int V_16 = 0 ;
F_6 ( & V_17 ) ;
V_13 = V_18 ;
V_14 = V_12 + V_7 ;
if ( F_7 ( V_13 , V_14 ) ) {
V_15 = ( long ) ( V_14 ) - ( long ) V_13 ;
F_8 ( V_19 ) ;
if ( F_9 ( V_15 ) > 0 ) {
V_16 = - V_20 ;
goto V_21;
}
V_13 = V_18 ;
}
V_12 = V_13 ;
V_21:
F_10 ( & V_17 ) ;
return V_16 ;
}
static int F_11 ( struct V_22 * V_23 ,
T_3 * V_24 , T_3 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 = F_12 ( V_27 , V_29 ) ;
int V_16 ;
V_27 = (struct V_26 * ) V_31 . V_32 ;
V_27 -> V_33 = V_34 ;
V_16 = F_13 ( V_23 , & V_31 ) ;
if ( V_16 < 0 )
return 0 ;
switch ( V_31 . V_35 ) {
case V_36 :
if ( V_24 )
* V_24 = 0 ;
if ( V_25 )
* V_25 = 0 ;
return 1 ;
case V_37 :
V_29 = (struct V_28 * ) V_31 . V_38 ;
if ( V_24 )
* V_24 = V_29 -> V_39 . V_40 ;
if ( V_25 )
* V_25 = V_29 -> V_39 . V_41 ;
return 1 ;
}
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_3 V_39 , V_41 ;
struct V_22 * V_23 = F_15 ( V_2 ) ;
int V_16 ;
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
if ( ! F_11 ( V_23 , & V_39 , & V_41 ) )
return - V_42 ;
return F_2 ( V_5 , V_9 , L_2 , V_39 , V_41 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 = F_12 ( V_27 , V_29 ) ;
int V_16 ;
unsigned int V_43 ;
struct V_22 * V_23 = F_15 ( V_2 ) ;
if ( F_17 ( V_5 , 0 , & V_43 ) )
return - V_11 ;
V_27 = (struct V_26 * ) V_31 . V_32 ;
V_27 -> V_33 = V_44 ;
V_27 -> V_45 . V_40 = V_43 ;
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
V_16 = F_13 ( V_23 , & V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_31 . V_35 != V_37 )
return - V_11 ;
return V_10 ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 = F_12 ( V_27 , V_29 ) ;
struct V_22 * V_23 = F_15 ( V_2 ) ;
unsigned int V_43 [ 4 ] ;
int V_16 , V_46 = 0 , V_47 = 0 , V_48 = 0 ;
do {
while ( * V_5 && isspace ( * V_5 ) )
V_5 ++ ;
if ( ! * V_5 )
break;
V_16 = sscanf ( V_5 , L_3 , & V_43 [ V_46 ++ ] ) ;
if ( V_16 == 0 )
return - V_11 ;
if ( V_46 == 4 ) {
V_27 = (struct V_26 * ) V_31 . V_32 ;
V_27 -> V_33 = V_49 ;
V_27 -> V_50 . V_51 = V_43 [ 0 ] ;
V_27 -> V_50 . V_52 = V_43 [ 1 ] ;
V_27 -> V_50 . V_53 = V_43 [ 2 ] ;
V_27 -> V_50 . V_54 = V_43 [ 3 ] ;
if ( ( V_47 ++ % 4 ) == 0 ) {
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
}
V_16 = F_13 ( V_23 , & V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_31 . V_35 != V_37 )
return - V_11 ;
V_46 = 0 ;
V_48 = 1 ;
}
while ( * V_5 && ! isspace ( * V_5 ) )
V_5 ++ ;
} while ( * V_5 );
return ( V_48 && V_46 == 0 ) ? V_10 : - V_11 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 = F_12 ( V_27 , V_29 ) ;
int V_16 ;
struct V_22 * V_23 = F_15 ( V_2 ) ;
V_27 = (struct V_26 * ) V_31 . V_32 ;
V_27 -> V_33 = V_55 ;
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
V_16 = F_13 ( V_23 , & V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_31 . V_35 != V_37 )
return F_2 ( V_5 , V_9 ,
L_4 , V_31 . V_35 ) ;
V_29 = (struct V_28 * ) V_31 . V_38 ;
if ( V_29 -> V_56 . V_40 >= F_20 ( V_57 ) )
return F_2 ( V_5 , V_9 , L_5 , V_29 -> V_56 . V_40 ) ;
else
return F_2 ( V_5 , V_9 , L_6 ,
V_57 [ V_29 -> V_56 . V_40 ] ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 = F_12 ( V_27 , V_29 ) ;
unsigned int V_40 ;
int V_16 , V_58 ;
struct V_22 * V_23 = F_15 ( V_2 ) ;
for ( V_58 = 0 ; V_58 < V_10 ; V_58 ++ )
if ( ! isalnum ( V_5 [ V_58 ] ) )
break;
for ( V_40 = 0 ; V_40 < F_20 ( V_57 ) ; V_40 ++ )
if ( ! strncasecmp ( V_57 [ V_40 ] , V_5 , V_58 ) )
break;
if ( V_40 >= F_20 ( V_57 ) ) {
V_16 = F_17 ( V_5 , 0 , & V_40 ) ;
if ( V_16 )
return V_16 ;
}
V_27 = (struct V_26 * ) V_31 . V_32 ;
V_27 -> V_33 = V_59 ;
V_27 -> V_60 . V_40 = V_40 ;
V_16 = F_5 () ;
if ( V_16 )
return V_16 ;
V_16 = F_13 ( V_23 , & V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_31 . V_35 != V_37 )
return - V_11 ;
return V_10 ;
}
void F_22 ( struct V_22 * V_23 )
{
int V_16 = 0 ;
if ( ! F_11 ( V_23 , NULL , NULL ) )
return;
V_16 = F_23 ( & V_23 -> V_61 -> V_62 , & V_63 ) ;
if ( V_16 )
F_24 ( L_7 , V_16 ) ;
}
void F_25 ( struct V_22 * V_23 )
{
F_26 ( & V_23 -> V_61 -> V_62 , & V_63 ) ;
}
