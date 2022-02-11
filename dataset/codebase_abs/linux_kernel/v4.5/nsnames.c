char * F_1 ( struct V_1 * V_2 )
{
char * V_3 ;
F_2 ( V_4 , V_2 ) ;
V_3 = F_3 ( V_2 , FALSE ) ;
F_4 ( V_3 ) ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_6 () ;
V_5 = F_7 ( V_2 , NULL , 0 , FALSE ) ;
return ( V_5 ) ;
}
T_2
F_8 ( T_3 V_6 ,
struct V_7 * V_8 , T_4 V_9 )
{
T_2 V_10 ;
struct V_1 * V_2 ;
T_1 V_11 ;
F_2 ( V_12 , V_6 ) ;
V_2 = F_9 ( V_6 ) ;
if ( ! V_2 ) {
F_10 ( V_13 ) ;
}
V_11 =
F_7 ( V_2 , NULL , 0 , V_9 ) ;
if ( ! V_11 ) {
F_10 ( V_13 ) ;
}
V_10 = F_11 ( V_8 , V_11 ) ;
if ( F_12 ( V_10 ) ) {
F_10 ( V_10 ) ;
}
( void ) F_7 ( V_2 , V_8 -> V_14 ,
V_11 , V_9 ) ;
if ( F_12 ( V_10 ) ) {
F_10 ( V_10 ) ;
}
F_13 ( ( V_15 , L_1 ,
( char * ) V_8 -> V_14 , ( V_16 ) V_11 ) ) ;
F_10 ( V_17 ) ;
}
V_16
F_7 ( struct V_1 * V_2 ,
char * V_18 , V_16 V_19 , T_4 V_9 )
{
V_16 V_20 = 0 , V_21 ;
char V_22 [ V_23 ] ;
T_4 V_24 ;
char V_25 , * V_26 , * V_27 ;
struct V_1 * V_28 ;
F_2 ( V_29 , V_2 ) ;
#define F_14 ( T_5 , V_5 , T_6 , V_20 ) \
do { \
if ((length) < (size)) \
{ \
(path)[(length)] = (byte); \
} \
(length)++; \
} while (0)
if ( ! V_18 ) {
V_19 = 0 ;
}
if ( ! V_2 ) {
goto V_30;
}
V_28 = V_2 ;
while ( V_28 && V_28 != V_31 ) {
if ( V_28 != V_2 ) {
F_14 ( V_18 , V_19 ,
V_32 , V_20 ) ;
}
F_15 ( V_22 , & V_28 -> V_22 ) ;
V_24 = V_9 ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_25 = V_22 [ 4 - V_21 - 1 ] ;
if ( V_24 && V_25 != '_' ) {
V_24 = FALSE ;
}
if ( ! V_24 ) {
F_14 ( V_18 , V_19 , V_25 , V_20 ) ;
}
}
V_28 = V_28 -> V_33 ;
}
F_14 ( V_18 , V_19 , V_34 , V_20 ) ;
if ( V_20 <= V_19 ) {
V_26 = V_18 ;
V_27 = V_18 + V_20 - 1 ;
while ( V_26 < V_27 ) {
V_25 = * V_26 ;
* V_26 ++ = * V_27 ;
* V_27 -- = V_25 ;
}
}
V_30:
F_14 ( V_18 , V_19 , '\0' , V_20 ) ;
#undef F_14
F_16 ( V_20 ) ;
}
char * F_3 ( struct V_1 * V_2 ,
T_4 V_9 )
{
char * V_3 ;
T_1 V_5 ;
F_2 ( V_35 , V_2 ) ;
V_5 = F_7 ( V_2 , NULL , 0 , V_9 ) ;
if ( ! V_5 ) {
F_4 ( NULL ) ;
}
V_3 = F_17 ( V_5 ) ;
if ( ! V_3 ) {
F_18 ( ( V_36 , L_2 , ( V_16 ) V_5 ) ) ;
F_4 ( NULL ) ;
}
( void ) F_7 ( V_2 , V_3 , V_5 ,
V_9 ) ;
F_4 ( V_3 ) ;
}
