int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
if ( ! ( V_6 = F_2 () ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
V_6 -> type = V_9 ;
if ( ! ( V_5 = F_4 () ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
if ( ! F_5 ( V_5 , V_2 , V_3 ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
V_6 -> V_10 . V_11 = V_5 ;
if ( ! ( V_4 = F_6 () ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
V_4 -> V_12 = F_7 ( V_13 ) ;
if ( ! ( V_4 -> V_10 . V_14 = F_8 ( NULL ) ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
F_9 ( V_4 -> V_10 . V_14 , V_6 ) ;
V_4 -> V_14 = 1 ;
if ( ! V_1 -> V_4 && ! ( V_1 -> V_4 = F_10 ( NULL ) ) ) {
F_3 ( V_7 , V_8 ) ;
return 0 ;
}
F_11 ( V_1 -> V_4 , V_4 ) ;
return 1 ;
}
int F_12 ( T_5 * V_15 , int V_16 )
{
T_2 * V_4 ;
T_6 * V_17 ;
T_4 * V_6 ;
unsigned char V_18 ;
V_18 = ( unsigned char ) V_16 ;
if ( ! ( V_6 = F_2 () ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
V_6 -> type = V_20 ;
if ( ! ( V_17 = F_13 () ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
if ( ! F_14 ( V_17 , & V_18 , 1 ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
V_6 -> V_10 . V_21 = V_17 ;
if ( ! ( V_4 = F_6 () ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
V_4 -> V_12 = F_7 ( V_22 ) ;
if ( ! ( V_4 -> V_10 . V_14 = F_8 ( NULL ) ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
F_9 ( V_4 -> V_10 . V_14 , V_6 ) ;
V_4 -> V_14 = 1 ;
if ( ! V_15 -> V_23
&& ! ( V_15 -> V_23 = F_10 ( NULL ) ) ) {
F_3 ( V_19 , V_8 ) ;
return 0 ;
}
F_11 ( V_15 -> V_23 , V_4 ) ;
return 1 ;
}
int F_15 ( T_1 * V_1 , const char * V_2 ,
int V_3 )
{
unsigned char * V_24 ;
int V_25 , V_26 ;
if ( ! F_16 ( V_2 , & V_24 , & V_26 ) ) {
F_3 ( V_27 ,
V_8 ) ;
return 0 ;
}
V_25 = F_17 ( V_1 , V_24 , V_26 ) ;
Free ( V_24 ) ;
return V_25 ;
}
int F_17 ( T_1 * V_1 ,
const unsigned char * V_2 , int V_3 )
{
T_2 * V_4 ;
T_3 * V_28 ;
T_4 * V_29 ;
if( ! V_2 [ V_3 - 1 ] && ! V_2 [ V_3 - 2 ] ) V_3 -= 2 ;
if ( ! ( V_29 = F_2 () ) ) {
F_3 ( V_30 ,
V_8 ) ;
return 0 ;
}
V_29 -> type = V_31 ;
if ( ! ( V_28 = F_18 () ) ) {
F_3 ( V_30 ,
V_8 ) ;
return 0 ;
}
if ( ! ( V_28 -> V_32 = Malloc ( V_3 ) ) ) {
F_3 ( V_30 ,
V_8 ) ;
return 0 ;
}
memcpy ( V_28 -> V_32 , V_2 , V_3 ) ;
V_28 -> V_33 = V_3 ;
V_29 -> V_10 . V_34 = V_28 ;
if ( ! ( V_4 = F_6 () ) ) {
F_3 ( V_30 ,
V_8 ) ;
return 0 ;
}
V_4 -> V_12 = F_7 ( V_35 ) ;
if ( ! ( V_4 -> V_10 . V_14 = F_8 ( NULL ) ) ) {
F_3 ( V_36 ,
V_8 ) ;
return 0 ;
}
F_9 ( V_4 -> V_10 . V_14 , V_29 ) ;
V_4 -> V_14 = 1 ;
if ( ! V_1 -> V_4 && ! ( V_1 -> V_4 = F_10 ( NULL ) ) ) {
F_3 ( V_30 ,
V_8 ) ;
return 0 ;
}
F_11 ( V_1 -> V_4 , V_4 ) ;
return V_37 ;
}
char * F_19 ( T_1 * V_1 )
{
T_4 * V_38 ;
if ( ! ( V_38 = F_20 ( V_1 , V_35 ) ) ) return NULL ;
if ( V_38 -> type != V_31 ) return NULL ;
return F_21 ( V_38 -> V_10 . V_34 -> V_32 ,
V_38 -> V_10 . V_34 -> V_33 ) ;
}
