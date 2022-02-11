static void * F_1 ( const char * V_1 , T_1 * V_2 )
{
int V_3 ;
struct V_4 V_4 ;
void * V_5 ;
const T_2 * V_6 ;
V_3 = F_2 ( V_1 , V_7 ) ;
if ( V_3 < 0 ) {
fprintf ( V_8 , L_1 , V_9 ,
V_1 , strerror ( V_10 ) ) ;
return NULL ;
}
if ( F_3 ( V_3 , & V_4 ) != 0 ) {
fprintf ( V_8 , L_2 , V_9 ,
V_1 , strerror ( V_10 ) ) ;
return NULL ;
}
V_5 = F_4 ( NULL , V_4 . V_11 , V_12 | V_13 , V_14 , V_3 ,
0 ) ;
if ( V_5 == V_15 ) {
fprintf ( V_8 , L_3 , V_9 ,
V_1 , strerror ( V_10 ) ) ;
return NULL ;
}
V_6 = V_5 ;
if ( memcmp ( V_6 -> V_16 , V_17 , V_18 ) != 0 ) {
fprintf ( V_8 , L_4 , V_9 ,
V_1 ) ;
return NULL ;
}
V_19 = V_6 -> V_16 [ V_20 ] ;
switch ( V_19 ) {
case V_21 :
case V_22 :
break;
default:
fprintf ( V_8 , L_5 ,
V_9 , V_1 ) ;
return NULL ;
}
switch ( V_6 -> V_16 [ V_23 ] ) {
case V_24 :
case V_25 :
V_26 = V_6 -> V_16 [ V_23 ] != V_27 ;
break;
default:
fprintf ( V_8 , L_6 ,
V_9 , V_1 ) ;
return NULL ;
}
if ( F_5 ( V_6 -> V_28 ) != V_29 ) {
fprintf ( V_8 ,
L_7 ,
V_9 , V_1 ) ;
return NULL ;
} else if ( F_5 ( V_6 -> V_30 ) != V_31 ) {
fprintf ( V_8 ,
L_8 ,
V_9 , V_1 ) ;
return NULL ;
}
* V_2 = V_4 . V_11 ;
return V_5 ;
}
static bool F_6 ( const char * V_1 , void * V_32 )
{
if ( V_19 == V_22 )
return F_7 ( V_1 , V_32 ) ;
else
return F_8 ( V_1 , V_32 ) ;
}
static bool F_9 ( const char * V_1 , void * V_32 )
{
if ( V_19 == V_22 )
return F_10 ( V_1 , V_32 ) ;
else
return F_11 ( V_1 , V_32 ) ;
}
int main ( int V_33 , char * * V_34 )
{
const char * V_35 , * V_36 , * V_37 ;
void * V_38 , * V_32 ;
T_1 V_39 , V_40 , V_41 ;
V_9 = V_34 [ 0 ] ;
if ( V_33 < 4 || V_33 > 5 ) {
fprintf ( V_8 ,
L_9 ,
V_9 ) ;
return V_42 ;
}
V_35 = V_34 [ 1 ] ;
V_36 = V_34 [ 2 ] ;
V_37 = V_34 [ 3 ] ;
V_43 = ( V_33 > 4 ) ? V_34 [ 4 ] : L_10 ;
V_38 = F_1 ( V_35 , & V_39 ) ;
if ( ! V_38 )
return V_42 ;
V_32 = F_1 ( V_36 , & V_40 ) ;
if ( ! V_32 )
return V_42 ;
if ( ! F_6 ( V_35 , V_38 ) )
return V_42 ;
if ( ! F_6 ( V_36 , V_32 ) )
return V_42 ;
if ( F_12 ( V_38 , V_39 , V_44 ) != 0 ) {
fprintf ( V_8 , L_11 , V_9 ,
V_35 , strerror ( V_10 ) ) ;
return V_42 ;
} else if ( F_12 ( V_32 , V_40 , V_44 ) != 0 ) {
fprintf ( V_8 , L_11 , V_9 ,
V_36 , strerror ( V_10 ) ) ;
return V_42 ;
}
V_45 = fopen ( V_37 , L_12 ) ;
if ( ! V_45 ) {
fprintf ( V_8 , L_1 , V_9 ,
V_37 , strerror ( V_10 ) ) ;
return V_42 ;
}
fprintf ( V_45 , L_13 ) ;
fprintf ( V_45 , L_14 ) ;
fprintf ( V_45 , L_15 ) ;
fprintf ( V_45 , L_16 ) ;
fprintf ( V_45 ,
L_17 ,
V_40 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
if ( ! ( V_41 % 10 ) )
fprintf ( V_45 , L_18 ) ;
fprintf ( V_45 , L_19 , ( ( unsigned char * ) V_32 ) [ V_41 ] ) ;
}
fprintf ( V_45 , L_20 ) ;
fprintf ( V_45 ,
L_21 ,
V_40 ) ;
fprintf ( V_45 , L_22 ,
( V_43 [ 0 ] ) ? L_23 : L_10 , V_43 ) ;
fprintf ( V_45 , L_24 ) ;
fprintf ( V_45 , L_25 , V_40 ) ;
fprintf ( V_45 , L_26 ) ;
fprintf ( V_45 , L_27 ) ;
fprintf ( V_45 , L_28 ) ;
fprintf ( V_45 , L_29 ) ;
if ( ! F_9 ( V_35 , V_38 ) ) {
F_13 ( V_37 ) ;
return V_42 ;
}
fprintf ( V_45 , L_30 ) ;
return V_46 ;
}
