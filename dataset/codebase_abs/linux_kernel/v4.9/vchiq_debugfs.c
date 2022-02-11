static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int * V_4 = V_2 -> V_5 ;
char * V_6 = NULL ;
switch ( * V_4 ) {
case V_7 :
V_6 = V_8 ;
break;
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
case V_13 :
V_6 = V_14 ;
break;
default:
break;
}
F_2 ( V_2 , L_1 , V_6 ? V_6 : L_2 ) ;
return 0 ;
}
static int F_3 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_4 ( V_16 , F_1 , V_15 -> V_17 ) ;
}
static int F_5 ( struct V_16 * V_16 ,
const char T_1 * V_18 ,
T_2 V_19 , T_3 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_21 ;
int * V_4 = V_2 -> V_5 ;
char V_22 [ V_23 + 1 ] ;
memset ( V_22 , 0 , V_23 + 1 ) ;
if ( V_19 >= V_23 )
V_19 = V_23 ;
if ( F_6 ( V_22 , V_18 , V_19 ) != 0 )
return - V_24 ;
V_22 [ V_19 - 1 ] = 0 ;
if ( strncmp ( L_3 , V_22 , strlen ( L_3 ) ) == 0 )
* V_4 = V_7 ;
else if ( strncmp ( L_4 , V_22 , strlen ( L_4 ) ) == 0 )
* V_4 = V_9 ;
else if ( strncmp ( L_5 , V_22 , strlen ( L_5 ) ) == 0 )
* V_4 = V_11 ;
else if ( strncmp ( L_6 , V_22 , strlen ( L_6 ) ) == 0 )
* V_4 = V_13 ;
else
* V_4 = V_25 ;
* V_20 += V_19 ;
return V_19 ;
}
static int F_7 ( struct V_26 * V_27 )
{
struct V_26 * V_28 ;
T_2 V_29 ;
int V_30 = 0 ;
V_28 = F_8 ( L_7 , F_9 () ) ;
if ( ! V_28 )
return - V_31 ;
V_32 . V_33 = V_28 ;
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ ) {
void * V_4 = ( void * ) V_35 [ V_29 ] . V_36 ;
V_28 = F_10 ( V_35 [ V_29 ] . V_37 ,
0644 ,
V_32 . V_33 ,
V_4 ,
& V_38 ) ;
if ( ! V_28 ) {
V_30 = - V_31 ;
break;
}
V_35 [ V_29 ] . V_28 = V_28 ;
}
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 )
{
T_4 V_39 = V_2 -> V_5 ;
int V_40 ;
V_40 = F_12 ( V_39 ) ;
F_2 ( V_2 , L_8 , V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_4 ( V_16 , F_11 , V_15 -> V_17 ) ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
T_4 V_39 = V_2 -> V_5 ;
int V_41 ;
V_41 = F_15 ( V_39 ) ;
F_2 ( V_2 , L_1 , V_41 ? L_9 : L_10 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_4 ( V_16 , F_14 , V_15 -> V_17 ) ;
}
static int F_17 ( struct V_16 * V_16 ,
const char T_1 * V_18 ,
T_2 V_19 , T_3 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_21 ;
T_4 V_39 = V_2 -> V_5 ;
char V_42 ;
if ( F_6 ( & V_42 , V_18 , 1 ) != 0 )
return - V_24 ;
switch ( V_42 ) {
case 'Y' :
case 'y' :
case '1' :
F_18 ( V_39 , 1 ) ;
break;
case 'N' :
case 'n' :
case '0' :
F_18 ( V_39 , 0 ) ;
break;
default:
break;
}
* V_20 += V_19 ;
return V_19 ;
}
int F_19 ( T_4 V_39 )
{
char V_43 [ 16 ] ;
struct V_26 * V_27 , * V_40 , * V_41 ;
struct V_26 * V_44 = F_20 () ;
snprintf ( V_43 , sizeof( V_43 ) , L_11 ,
F_21 ( V_39 ) ) ;
V_27 = F_8 ( V_43 , V_44 ) ;
if ( ! V_27 )
goto V_45;
V_40 = F_10 ( L_12 ,
0444 , V_27 ,
V_39 ,
& V_46 ) ;
if ( ! V_40 )
goto V_47;
V_41 = F_10 ( L_6 ,
0644 , V_27 ,
V_39 ,
& V_48 ) ;
if ( ! V_41 )
goto V_49;
F_22 ( V_39 ) -> V_26 = V_27 ;
return 0 ;
V_49:
F_23 ( V_40 ) ;
V_47:
F_23 ( V_27 ) ;
V_45:
return - V_31 ;
}
void F_24 ( T_4 V_39 )
{
T_5 * V_50 = F_22 ( V_39 ) ;
F_25 ( V_50 -> V_26 ) ;
}
int F_26 ( void )
{
F_27 ( V_32 . V_51 != NULL ) ;
V_32 . V_51 = F_8 ( L_13 , NULL ) ;
if ( V_32 . V_51 == NULL )
goto V_52;
V_32 . V_44 = F_8 ( L_14 ,
F_9 () ) ;
if ( ! V_32 . V_44 )
goto V_52;
if ( F_7 ( F_9 () ) != 0 )
goto V_52;
return 0 ;
V_52:
F_28 () ;
F_29 ( V_53 ,
L_15 ,
V_54 ) ;
return - V_31 ;
}
void F_28 ( void )
{
F_25 ( F_9 () ) ;
}
static struct V_26 * F_20 ( void )
{
return V_32 . V_44 ;
}
static struct V_26 * F_9 ( void )
{
F_27 ( V_32 . V_51 == NULL ) ;
return V_32 . V_51 ;
}
int F_26 ( void )
{
return 0 ;
}
void F_28 ( void )
{
}
int F_19 ( T_4 V_39 )
{
return 0 ;
}
void F_24 ( T_4 V_39 )
{
}
