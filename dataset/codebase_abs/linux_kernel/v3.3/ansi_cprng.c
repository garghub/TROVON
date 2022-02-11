static void F_1 ( char * V_1 , unsigned char * V_2 , unsigned int V_3 )
{
if ( V_4 ) {
F_2 ( V_5 L_1 , V_1 ) ;
F_3 ( V_6 , L_2 , V_7 ,
16 , 1 ,
V_2 , V_3 , false ) ;
}
}
static void F_4 ( unsigned char * V_8 , unsigned char * V_9 ,
unsigned char * V_10 , unsigned int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_10 [ V_12 ] = V_8 [ V_12 ] ^ V_9 [ V_12 ] ;
}
static int F_5 ( struct V_13 * V_14 , int V_15 )
{
int V_12 ;
unsigned char V_16 [ V_17 ] ;
unsigned char * V_18 = NULL ;
F_6 ( V_5 L_3 ,
V_14 ) ;
F_1 ( L_4 , V_14 -> V_19 , V_17 ) ;
F_1 ( L_5 , V_14 -> V_20 , V_17 ) ;
F_1 ( L_6 , V_14 -> V_21 , V_17 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
switch ( V_12 ) {
case 0 :
memcpy ( V_16 , V_14 -> V_19 , V_17 ) ;
V_18 = V_14 -> V_20 ;
F_1 ( L_7 , V_16 , V_17 ) ;
break;
case 1 :
F_4 ( V_14 -> V_20 , V_14 -> V_21 , V_16 , V_17 ) ;
F_1 ( L_8 , V_16 , V_17 ) ;
V_18 = V_14 -> V_22 ;
break;
case 2 :
if ( ! memcmp ( V_14 -> V_22 , V_14 -> V_23 ,
V_17 ) ) {
if ( V_15 ) {
F_7 ( L_9 ,
V_14 ) ;
}
F_2 ( V_24
L_10 ,
V_14 ) ;
V_14 -> V_25 |= V_26 ;
return - V_27 ;
}
memcpy ( V_14 -> V_23 , V_14 -> V_22 ,
V_17 ) ;
F_4 ( V_14 -> V_22 , V_14 -> V_20 , V_16 ,
V_17 ) ;
V_18 = V_14 -> V_21 ;
F_1 ( L_11 , V_16 , V_17 ) ;
break;
}
F_8 ( V_14 -> V_28 , V_18 , V_16 ) ;
}
for ( V_12 = V_17 - 1 ; V_12 >= 0 ; V_12 -- ) {
V_14 -> V_19 [ V_12 ] += 1 ;
if ( V_14 -> V_19 [ V_12 ] != 0 )
break;
}
F_6 ( L_12 , V_14 ) ;
V_14 -> V_29 = 0 ;
F_1 ( L_13 , V_14 -> V_19 , V_17 ) ;
F_1 ( L_14 , V_14 -> V_20 , V_17 ) ;
F_1 ( L_15 , V_14 -> V_21 , V_17 ) ;
F_1 ( L_16 , V_14 -> V_22 , V_17 ) ;
return 0 ;
}
static int F_9 ( char * V_2 , T_1 V_30 , struct V_13 * V_14 ,
int V_31 )
{
unsigned char * V_32 = V_2 ;
unsigned int V_33 = ( unsigned int ) V_30 ;
int V_34 ;
F_10 ( & V_14 -> V_35 ) ;
V_34 = - V_27 ;
if ( V_14 -> V_25 & V_26 )
goto V_36;
V_34 = - V_27 ;
if ( V_14 -> V_25 & V_37 ) {
if ( V_30 < V_17 )
goto V_36;
V_33 = V_17 ;
}
V_34 = V_33 ;
F_6 ( V_5 L_17 ,
V_33 , V_14 ) ;
V_38:
if ( V_14 -> V_29 == V_17 ) {
if ( F_5 ( V_14 , V_31 ) < 0 ) {
memset ( V_2 , 0 , V_30 ) ;
V_34 = - V_27 ;
goto V_36;
}
}
if ( V_33 < V_17 ) {
V_39:
for (; V_14 -> V_29 < V_17 ;
V_14 -> V_29 ++ ) {
* V_32 = V_14 -> V_22 [ V_14 -> V_29 ] ;
V_32 ++ ;
V_33 -- ;
if ( V_33 == 0 )
goto V_36;
}
}
for (; V_33 >= V_17 ; V_33 -= V_17 ) {
if ( V_14 -> V_29 == V_17 ) {
if ( F_5 ( V_14 , V_31 ) < 0 ) {
memset ( V_2 , 0 , V_30 ) ;
V_34 = - V_27 ;
goto V_36;
}
}
if ( V_14 -> V_29 > 0 )
goto V_39;
memcpy ( V_32 , V_14 -> V_22 , V_17 ) ;
V_14 -> V_29 += V_17 ;
V_32 += V_17 ;
}
if ( V_33 )
goto V_38;
V_36:
F_11 ( & V_14 -> V_35 ) ;
F_6 ( V_5 L_18 ,
V_34 , V_14 ) ;
return V_34 ;
}
static void F_12 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_28 ) ;
}
static int F_14 ( struct V_13 * V_14 ,
unsigned char * V_40 , T_1 V_41 ,
unsigned char * V_21 , unsigned char * V_19 )
{
int V_42 ;
unsigned char * V_43 ;
F_10 ( & V_14 -> V_35 ) ;
V_14 -> V_25 |= V_26 ;
V_43 = ( V_40 != NULL ) ? V_40 : ( unsigned char * ) V_44 ;
if ( ! V_40 )
V_41 = V_45 ;
if ( V_21 )
memcpy ( V_14 -> V_21 , V_21 , V_17 ) ;
else
memcpy ( V_14 -> V_21 , V_46 , V_17 ) ;
if ( V_19 )
memcpy ( V_14 -> V_19 , V_19 , V_17 ) ;
else
memset ( V_14 -> V_19 , 0 , V_17 ) ;
memset ( V_14 -> V_22 , 0 , V_17 ) ;
memset ( V_14 -> V_23 , 0 , V_17 ) ;
V_14 -> V_29 = V_17 ;
V_42 = F_15 ( V_14 -> V_28 , V_43 , V_41 ) ;
if ( V_42 ) {
F_6 ( V_5 L_19 ,
F_16 ( V_14 -> V_28 ) ) ;
goto V_10;
}
V_42 = 0 ;
V_14 -> V_25 &= ~ V_26 ;
V_10:
F_11 ( & V_14 -> V_35 ) ;
return V_42 ;
}
static int F_17 ( struct V_47 * V_28 )
{
struct V_13 * V_14 = F_18 ( V_28 ) ;
F_19 ( & V_14 -> V_35 ) ;
V_14 -> V_28 = F_20 ( L_20 , 0 , 0 ) ;
if ( F_21 ( V_14 -> V_28 ) ) {
F_6 ( V_5 L_21 ,
V_14 ) ;
return F_22 ( V_14 -> V_28 ) ;
}
if ( F_14 ( V_14 , NULL , V_45 , NULL , NULL ) < 0 )
return - V_27 ;
V_14 -> V_25 |= V_26 ;
return 0 ;
}
static void F_23 ( struct V_47 * V_28 )
{
F_12 ( F_18 ( V_28 ) ) ;
}
static int F_24 ( struct V_48 * V_28 , T_2 * V_49 ,
unsigned int V_50 )
{
struct V_13 * V_51 = F_25 ( V_28 ) ;
return F_9 ( V_49 , V_50 , V_51 , 0 ) ;
}
static int F_26 ( struct V_48 * V_28 , T_2 * V_52 , unsigned int V_53 )
{
struct V_13 * V_51 = F_25 ( V_28 ) ;
T_2 * V_40 = V_52 + V_17 ;
T_2 * V_54 = NULL ;
if ( V_53 < V_45 + V_17 )
return - V_27 ;
if ( V_53 >= ( 2 * V_17 + V_45 ) )
V_54 = V_40 + V_45 ;
F_14 ( V_51 , V_40 , V_45 , V_52 , V_54 ) ;
if ( V_51 -> V_25 & V_26 )
return - V_27 ;
return 0 ;
}
static int F_27 ( struct V_48 * V_28 , T_2 * V_49 ,
unsigned int V_50 )
{
struct V_13 * V_51 = F_25 ( V_28 ) ;
return F_9 ( V_49 , V_50 , V_51 , 1 ) ;
}
static int F_28 ( struct V_48 * V_28 , T_2 * V_52 , unsigned int V_53 )
{
T_2 V_49 [ V_17 ] ;
T_2 * V_40 = V_52 + V_17 ;
int V_55 ;
struct V_13 * V_51 = F_25 ( V_28 ) ;
if ( V_53 < V_45 + V_17 )
return - V_27 ;
if ( ! memcmp ( V_52 , V_40 , V_45 ) )
return - V_27 ;
V_55 = F_26 ( V_28 , V_52 , V_53 ) ;
if ( ! V_55 )
goto V_10;
V_55 = F_9 ( V_49 , V_17 , V_51 , 0 ) ;
V_51 -> V_29 = V_17 ;
V_10:
return V_55 ;
}
static int T_3 F_29 ( void )
{
int V_55 = 0 ;
V_55 = F_30 ( & V_56 ) ;
#ifdef F_31
if ( V_55 )
goto V_10;
V_55 = F_30 ( & V_57 ) ;
V_10:
#endif
return V_55 ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_56 ) ;
#ifdef F_31
F_33 ( & V_57 ) ;
#endif
return;
}
