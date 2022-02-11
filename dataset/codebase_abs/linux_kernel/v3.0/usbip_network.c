void F_1 ( int V_1 , T_1 * V_2 )
{
T_1 V_3 ;
if ( V_1 )
V_3 = F_2 ( * V_2 ) ;
else
V_3 = F_3 ( * V_2 ) ;
* V_2 = V_3 ;
}
void F_4 ( int V_1 , T_2 * V_2 )
{
T_2 V_3 ;
if ( V_1 )
V_3 = F_5 ( * V_2 ) ;
else
V_3 = F_6 ( * V_2 ) ;
* V_2 = V_3 ;
}
void F_7 ( int V_1 , struct V_4 * V_5 )
{
F_1 ( V_1 , & V_5 -> V_6 ) ;
F_1 ( V_1 , & V_5 -> V_7 ) ;
F_1 ( V_1 , & V_5 -> V_8 ) ;
F_4 ( V_1 , & V_5 -> V_9 ) ;
F_4 ( V_1 , & V_5 -> V_10 ) ;
F_4 ( V_1 , & V_5 -> V_11 ) ;
}
static T_3 F_8 ( int V_12 , void * V_13 , T_4 V_14 , int V_15 )
{
T_3 V_16 = 0 ;
if ( ! V_14 )
return 0 ;
do {
T_3 V_17 ;
if ( V_15 )
V_17 = F_9 ( V_12 , V_13 , V_14 , 0 ) ;
else
V_17 = F_10 ( V_12 , V_13 , V_14 , V_18 ) ;
if ( V_17 <= 0 )
return - 1 ;
V_13 = ( void * ) ( ( V_19 ) V_13 + V_17 ) ;
V_14 -= V_17 ;
V_16 += V_17 ;
} while ( V_14 > 0 );
return V_16 ;
}
T_3 F_11 ( int V_12 , void * V_13 , T_4 V_14 )
{
return F_8 ( V_12 , V_13 , V_14 , 0 ) ;
}
T_3 F_12 ( int V_12 , void * V_13 , T_4 V_14 )
{
return F_8 ( V_12 , V_13 , V_14 , 1 ) ;
}
int F_13 ( int V_12 , T_1 V_20 , T_1 V_21 )
{
int V_22 ;
struct V_23 V_23 ;
F_14 ( & V_23 , sizeof( V_23 ) ) ;
V_23 . V_24 = V_25 ;
V_23 . V_20 = V_20 ;
V_23 . V_21 = V_21 ;
F_15 ( 1 , & V_23 ) ;
V_22 = F_12 ( V_12 , ( void * ) & V_23 , sizeof( V_23 ) ) ;
if ( V_22 < 0 ) {
F_16 ( L_1 ) ;
return - 1 ;
}
return 0 ;
}
int F_17 ( int V_12 , T_2 * V_20 )
{
int V_22 ;
struct V_23 V_23 ;
F_14 ( & V_23 , sizeof( V_23 ) ) ;
V_22 = F_11 ( V_12 , ( void * ) & V_23 , sizeof( V_23 ) ) ;
if ( V_22 < 0 ) {
F_16 ( L_2 , V_22 ) ;
goto F_16;
}
F_15 ( 0 , & V_23 ) ;
if ( V_23 . V_24 != V_25 ) {
F_16 ( L_3 , V_23 . V_24 , V_25 ) ;
goto F_16;
}
switch( * V_20 ) {
case V_26 :
break;
default:
if ( V_23 . V_20 != * V_20 ) {
F_18 ( L_4 , V_23 . V_20 , * V_20 ) ;
goto F_16;
}
}
if ( V_23 . V_21 != V_27 ) {
F_18 ( L_5 , V_23 . V_21 ) ;
goto F_16;
}
* V_20 = V_23 . V_20 ;
return 0 ;
F_16:
return - 1 ;
}
int F_19 ( int V_12 )
{
const int V_28 = 1 ;
int V_22 ;
V_22 = F_20 ( V_12 , V_29 , V_30 , & V_28 , sizeof( V_28 ) ) ;
if ( V_22 < 0 )
F_16 ( L_6 ) ;
return V_22 ;
}
int F_21 ( int V_12 )
{
const int V_28 = 1 ;
int V_22 ;
V_22 = F_20 ( V_12 , V_31 , V_32 , & V_28 , sizeof( V_28 ) ) ;
if ( V_22 < 0 )
F_16 ( L_7 ) ;
return V_22 ;
}
int F_22 ( int V_12 )
{
const int V_28 = 1 ;
int V_22 ;
V_22 = F_20 ( V_12 , V_29 , V_33 , & V_28 , sizeof( V_28 ) ) ;
if ( V_22 < 0 )
F_16 ( L_8 ) ;
return V_22 ;
}
int F_23 ( char * V_34 , char * V_35 )
{
struct V_36 V_37 , * V_38 , * V_39 ;
int V_12 ;
int F_16 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_40 = V_41 ;
F_16 = F_24 ( V_34 , V_35 , & V_37 , & V_39 ) ;
if ( F_16 ) {
F_16 ( L_9 , V_34 , V_35 , F_25 ( F_16 ) ) ;
return - 1 ;
}
for ( V_38 = V_39 ; V_38 ; V_38 = V_38 -> V_42 ) {
char V_43 [ V_44 ] , V_45 [ V_46 ] ;
F_16 = F_26 ( V_38 -> V_47 , V_38 -> V_48 ,
V_43 , sizeof( V_43 ) , V_45 , sizeof( V_45 ) , V_49 | V_50 ) ;
if ( F_16 ) {
F_16 ( L_9 , V_34 , V_35 , F_25 ( F_16 ) ) ;
continue;
}
F_27 ( L_10 , V_43 , V_45 ) ;
V_12 = F_28 ( V_38 -> V_51 , V_38 -> V_40 , V_38 -> V_52 ) ;
if ( V_12 < 0 ) {
F_16 ( L_11 ) ;
continue;
}
F_21 ( V_12 ) ;
F_22 ( V_12 ) ;
F_16 = F_29 ( V_12 , V_38 -> V_47 , V_38 -> V_48 ) ;
if ( F_16 < 0 ) {
F_30 ( V_12 ) ;
continue;
}
F_27 ( L_12 , V_43 , V_45 ) ;
F_31 ( V_39 ) ;
return V_12 ;
}
F_27 ( L_13 , V_34 , V_35 , L_14 ) ;
F_31 ( V_39 ) ;
return - 1 ;
}
