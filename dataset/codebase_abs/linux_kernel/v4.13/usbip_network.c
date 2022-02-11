void F_1 ( char * V_1 )
{
F_2 ( L_1 , V_1 ) ;
char * V_2 ;
unsigned long int V_3 = strtoul ( V_1 , & V_2 , 10 ) ;
if ( V_2 == V_1 ) {
F_3 ( L_2 , V_1 ) ;
return;
}
if ( * V_2 != '\0' ) {
F_3 ( L_3 , V_1 ) ;
return;
}
if ( V_3 > V_4 ) {
F_3 ( L_4 ,
V_1 , V_4 ) ;
return;
}
V_5 = V_3 ;
V_6 = V_1 ;
F_4 ( L_5 , V_5 , V_6 ) ;
}
void F_5 ( int V_7 , T_1 * V_8 )
{
T_1 V_9 ;
if ( V_7 )
V_9 = F_6 ( * V_8 ) ;
else
V_9 = F_7 ( * V_8 ) ;
* V_8 = V_9 ;
}
void F_8 ( int V_7 , T_2 * V_8 )
{
T_2 V_9 ;
if ( V_7 )
V_9 = F_9 ( * V_8 ) ;
else
V_9 = F_10 ( * V_8 ) ;
* V_8 = V_9 ;
}
void F_11 ( int V_7 , struct V_10 * V_11 )
{
F_5 ( V_7 , & V_11 -> V_12 ) ;
F_5 ( V_7 , & V_11 -> V_13 ) ;
F_5 ( V_7 , & V_11 -> V_14 ) ;
F_8 ( V_7 , & V_11 -> V_15 ) ;
F_8 ( V_7 , & V_11 -> V_16 ) ;
F_8 ( V_7 , & V_11 -> V_17 ) ;
}
static T_3 F_12 ( int V_18 , void * V_19 , T_4 V_20 ,
int V_21 )
{
T_3 V_22 ;
T_3 V_23 = 0 ;
if ( ! V_20 )
return 0 ;
do {
if ( V_21 )
V_22 = F_13 ( V_18 , V_19 , V_20 , 0 ) ;
else
V_22 = F_14 ( V_18 , V_19 , V_20 , V_24 ) ;
if ( V_22 <= 0 )
return - 1 ;
V_19 = ( void * ) ( ( V_25 ) V_19 + V_22 ) ;
V_20 -= V_22 ;
V_23 += V_22 ;
} while ( V_20 > 0 );
return V_23 ;
}
T_3 F_15 ( int V_18 , void * V_19 , T_4 V_20 )
{
return F_12 ( V_18 , V_19 , V_20 , 0 ) ;
}
T_3 F_16 ( int V_18 , void * V_19 , T_4 V_20 )
{
return F_12 ( V_18 , V_19 , V_20 , 1 ) ;
}
int F_17 ( int V_18 , T_1 V_26 , T_1 V_27 )
{
struct V_28 V_28 ;
int V_29 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_30 = V_31 ;
V_28 . V_26 = V_26 ;
V_28 . V_27 = V_27 ;
F_18 ( 1 , & V_28 ) ;
V_29 = F_16 ( V_18 , & V_28 , sizeof( V_28 ) ) ;
if ( V_29 < 0 ) {
F_2 ( L_6 , V_29 ) ;
return - 1 ;
}
return 0 ;
}
int F_19 ( int V_18 , T_2 * V_26 )
{
struct V_28 V_28 ;
int V_29 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_29 = F_15 ( V_18 , & V_28 , sizeof( V_28 ) ) ;
if ( V_29 < 0 ) {
F_2 ( L_7 , V_29 ) ;
goto F_3;
}
F_18 ( 0 , & V_28 ) ;
if ( V_28 . V_30 != V_31 ) {
F_2 ( L_8 , V_28 . V_30 ,
V_31 ) ;
goto F_3;
}
switch ( * V_26 ) {
case V_32 :
break;
default:
if ( V_28 . V_26 != * V_26 ) {
F_2 ( L_9 , V_28 . V_26 ,
* V_26 ) ;
goto F_3;
}
}
if ( V_28 . V_27 != V_33 ) {
F_2 ( L_10 , V_28 . V_27 ) ;
goto F_3;
}
* V_26 = V_28 . V_26 ;
return 0 ;
F_3:
return - 1 ;
}
int F_20 ( int V_18 )
{
const int V_34 = 1 ;
int V_35 ;
V_35 = F_21 ( V_18 , V_36 , V_37 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 < 0 )
F_2 ( L_11 ) ;
return V_35 ;
}
int F_22 ( int V_18 )
{
const int V_34 = 1 ;
int V_35 ;
V_35 = F_21 ( V_18 , V_38 , V_39 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 < 0 )
F_2 ( L_12 ) ;
return V_35 ;
}
int F_23 ( int V_18 )
{
const int V_34 = 1 ;
int V_35 ;
V_35 = F_21 ( V_18 , V_36 , V_40 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 < 0 )
F_2 ( L_13 ) ;
return V_35 ;
}
int F_24 ( int V_18 )
{
const int V_34 = 1 ;
int V_35 ;
V_35 = F_21 ( V_18 , V_41 , V_42 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 < 0 )
F_2 ( L_14 ) ;
return V_35 ;
}
int F_25 ( char * V_43 , char * V_44 )
{
struct V_45 V_46 , * V_47 , * V_48 ;
int V_18 ;
int V_35 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_49 = V_50 ;
V_46 . V_51 = V_52 ;
V_35 = F_26 ( V_43 , V_44 , & V_46 , & V_47 ) ;
if ( V_35 < 0 ) {
F_2 ( L_15 , V_43 , V_44 ,
F_27 ( V_35 ) ) ;
return V_35 ;
}
for ( V_48 = V_47 ; V_48 ; V_48 = V_48 -> V_53 ) {
V_18 = F_28 ( V_48 -> V_49 , V_48 -> V_51 ,
V_48 -> V_54 ) ;
if ( V_18 < 0 )
continue;
F_22 ( V_18 ) ;
F_23 ( V_18 ) ;
if ( F_29 ( V_18 , V_48 -> V_55 , V_48 -> V_56 ) == 0 )
break;
F_30 ( V_18 ) ;
}
F_31 ( V_47 ) ;
if ( ! V_48 )
return V_57 ;
return V_18 ;
}
