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
static T_3 F_8 ( int V_12 , void * V_13 , T_4 V_14 ,
int V_15 )
{
T_3 V_16 ;
T_3 V_17 = 0 ;
if ( ! V_14 )
return 0 ;
do {
if ( V_15 )
V_16 = F_9 ( V_12 , V_13 , V_14 , 0 ) ;
else
V_16 = F_10 ( V_12 , V_13 , V_14 , V_18 ) ;
if ( V_16 <= 0 )
return - 1 ;
V_13 = ( void * ) ( ( V_19 ) V_13 + V_16 ) ;
V_14 -= V_16 ;
V_17 += V_16 ;
} while ( V_14 > 0 );
return V_17 ;
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
struct V_22 V_22 ;
int V_23 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_24 = V_25 ;
V_22 . V_20 = V_20 ;
V_22 . V_21 = V_21 ;
F_14 ( 1 , & V_22 ) ;
V_23 = F_12 ( V_12 , & V_22 , sizeof( V_22 ) ) ;
if ( V_23 < 0 ) {
F_15 ( L_1 , V_23 ) ;
return - 1 ;
}
return 0 ;
}
int F_16 ( int V_12 , T_2 * V_20 )
{
struct V_22 V_22 ;
int V_23 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_23 = F_11 ( V_12 , & V_22 , sizeof( V_22 ) ) ;
if ( V_23 < 0 ) {
F_15 ( L_2 , V_23 ) ;
goto V_26;
}
F_14 ( 0 , & V_22 ) ;
if ( V_22 . V_24 != V_25 ) {
F_15 ( L_3 , V_22 . V_24 ,
V_25 ) ;
goto V_26;
}
switch ( * V_20 ) {
case V_27 :
break;
default:
if ( V_22 . V_20 != * V_20 ) {
F_15 ( L_4 , V_22 . V_20 ,
* V_20 ) ;
goto V_26;
}
}
if ( V_22 . V_21 != V_28 ) {
F_15 ( L_5 , V_22 . V_21 ) ;
goto V_26;
}
* V_20 = V_22 . V_20 ;
return 0 ;
V_26:
return - 1 ;
}
int F_17 ( int V_12 )
{
const int V_29 = 1 ;
int V_30 ;
V_30 = F_18 ( V_12 , V_31 , V_32 , & V_29 , sizeof( V_29 ) ) ;
if ( V_30 < 0 )
F_15 ( L_6 ) ;
return V_30 ;
}
int F_19 ( int V_12 )
{
const int V_29 = 1 ;
int V_30 ;
V_30 = F_18 ( V_12 , V_33 , V_34 , & V_29 , sizeof( V_29 ) ) ;
if ( V_30 < 0 )
F_15 ( L_7 ) ;
return V_30 ;
}
int F_20 ( int V_12 )
{
const int V_29 = 1 ;
int V_30 ;
V_30 = F_18 ( V_12 , V_31 , V_35 , & V_29 , sizeof( V_29 ) ) ;
if ( V_30 < 0 )
F_15 ( L_8 ) ;
return V_30 ;
}
int F_21 ( char * V_36 , char * V_37 )
{
struct V_38 V_39 , * V_40 , * V_41 ;
int V_12 ;
int V_30 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_42 = V_43 ;
V_39 . V_44 = V_45 ;
V_30 = F_22 ( V_36 , V_37 , & V_39 , & V_40 ) ;
if ( V_30 < 0 ) {
F_15 ( L_9 , V_36 , V_37 ,
F_23 ( V_30 ) ) ;
return V_30 ;
}
for ( V_41 = V_40 ; V_41 ; V_41 = V_41 -> V_46 ) {
V_12 = F_24 ( V_41 -> V_42 , V_41 -> V_44 ,
V_41 -> V_47 ) ;
if ( V_12 < 0 )
continue;
F_19 ( V_12 ) ;
F_20 ( V_12 ) ;
if ( F_25 ( V_12 , V_41 -> V_48 , V_41 -> V_49 ) == 0 )
break;
F_26 ( V_12 ) ;
}
if ( ! V_41 )
return V_50 ;
F_27 ( V_40 ) ;
return V_12 ;
}
