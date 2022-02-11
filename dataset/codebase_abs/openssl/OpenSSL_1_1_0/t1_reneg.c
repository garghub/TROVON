int F_1 ( T_1 * V_1 , unsigned char * V_2 , int * V_3 ,
int V_4 )
{
if ( V_2 ) {
if ( ( V_1 -> V_5 -> V_6 + 1 ) > V_4 ) {
F_2 ( V_7 ,
V_8 ) ;
return 0 ;
}
* V_2 = V_1 -> V_5 -> V_6 ;
V_2 ++ ;
memcpy ( V_2 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ;
}
* V_3 = V_1 -> V_5 -> V_6 + 1 ;
return 1 ;
}
int F_3 ( T_1 * V_1 , T_2 * V_10 , int * V_11 )
{
unsigned int V_12 ;
const unsigned char * V_13 ;
if ( ! F_4 ( V_10 , & V_12 )
|| ! F_5 ( V_10 , & V_13 , V_12 ) ) {
F_2 ( V_14 ,
V_15 ) ;
* V_11 = V_16 ;
return 0 ;
}
if ( V_12 != V_1 -> V_5 -> V_6 ) {
F_2 ( V_14 ,
V_17 ) ;
* V_11 = V_18 ;
return 0 ;
}
if ( memcmp ( V_13 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ) {
F_2 ( V_14 ,
V_17 ) ;
* V_11 = V_18 ;
return 0 ;
}
V_1 -> V_5 -> V_19 = 1 ;
return 1 ;
}
int F_6 ( T_1 * V_1 , unsigned char * V_2 , int * V_3 ,
int V_4 )
{
if ( V_2 ) {
if ( ( V_1 -> V_5 -> V_6 +
V_1 -> V_5 -> V_20 + 1 ) > V_4 ) {
F_2 ( V_21 ,
V_8 ) ;
return 0 ;
}
* V_2 = V_1 -> V_5 -> V_6 +
V_1 -> V_5 -> V_20 ;
V_2 ++ ;
memcpy ( V_2 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) ;
V_2 += V_1 -> V_5 -> V_6 ;
memcpy ( V_2 , V_1 -> V_5 -> V_22 ,
V_1 -> V_5 -> V_20 ) ;
}
* V_3 = V_1 -> V_5 -> V_6
+ V_1 -> V_5 -> V_20 + 1 ;
return 1 ;
}
int F_7 ( T_1 * V_1 , T_2 * V_10 , int * V_11 )
{
unsigned int V_23 = V_1 -> V_5 -> V_6
+ V_1 -> V_5 -> V_20 ;
unsigned int V_12 ;
const unsigned char * V_24 ;
F_8 ( ! V_23 || V_1 -> V_5 -> V_6 ) ;
F_8 ( ! V_23 || V_1 -> V_5 -> V_20 ) ;
if ( ! F_4 ( V_10 , & V_12 ) ) {
F_2 ( V_25 ,
V_15 ) ;
* V_11 = V_16 ;
return 0 ;
}
if ( F_9 ( V_10 ) != V_12 ) {
F_2 ( V_25 ,
V_15 ) ;
* V_11 = V_16 ;
return 0 ;
}
if ( V_12 != V_23 ) {
F_2 ( V_25 ,
V_17 ) ;
* V_11 = V_18 ;
return 0 ;
}
if ( ! F_5 ( V_10 , & V_24 , V_1 -> V_5 -> V_6 )
|| memcmp ( V_24 , V_1 -> V_5 -> V_9 ,
V_1 -> V_5 -> V_6 ) != 0 ) {
F_2 ( V_25 ,
V_17 ) ;
* V_11 = V_18 ;
return 0 ;
}
if ( ! F_5 ( V_10 , & V_24 , V_1 -> V_5 -> V_20 )
|| memcmp ( V_24 , V_1 -> V_5 -> V_22 ,
V_1 -> V_5 -> V_20 ) != 0 ) {
F_2 ( V_25 ,
V_17 ) ;
* V_11 = V_16 ;
return 0 ;
}
V_1 -> V_5 -> V_19 = 1 ;
return 1 ;
}
