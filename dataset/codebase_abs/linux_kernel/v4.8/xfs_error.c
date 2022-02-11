int
F_1 ( int V_1 , int * V_2 , char * V_3 ,
int line , char * V_4 , unsigned long V_5 )
{
int V_6 ;
T_1 V_7 ;
if ( F_2 () % V_5 )
return 0 ;
memcpy ( & V_7 , V_2 , sizeof( V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_10 [ V_6 ] == V_1 && V_11 [ V_6 ] == V_7 ) {
F_3 ( NULL ,
L_1 ,
V_3 , V_4 , line , V_12 [ V_6 ] ) ;
return 1 ;
}
}
return 0 ;
}
int
F_4 ( unsigned int V_1 , T_2 * V_13 )
{
int V_6 ;
int V_14 ;
T_1 V_7 ;
if ( V_1 >= V_15 )
return - V_16 ;
memcpy ( & V_7 , V_13 -> V_17 , sizeof( V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_11 [ V_6 ] == V_7 && V_10 [ V_6 ] == V_1 ) {
F_3 ( V_13 , L_2 , V_1 ) ;
return 0 ;
}
}
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( V_10 [ V_6 ] == 0 ) {
F_3 ( V_13 , L_3 ,
V_1 ) ;
V_10 [ V_6 ] = V_1 ;
V_11 [ V_6 ] = V_7 ;
V_14 = strlen ( V_13 -> V_18 ) ;
V_12 [ V_6 ] = F_5 ( V_14 + 1 , V_19 ) ;
strcpy ( V_12 [ V_6 ] , V_13 -> V_18 ) ;
V_20 ++ ;
return 0 ;
}
}
F_3 ( V_13 , L_4 ) ;
return 1 ;
}
int
F_6 ( T_2 * V_13 , int V_21 )
{
T_1 V_7 ;
int V_22 = 0 ;
int V_6 ;
memcpy ( & V_7 , V_13 -> V_17 , sizeof( V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( ( V_7 == 0LL || V_11 [ V_6 ] == V_7 ) &&
V_10 [ V_6 ] != 0 ) {
V_22 = 1 ;
F_3 ( V_13 , L_5 ,
V_10 [ V_6 ] ) ;
V_10 [ V_6 ] = 0 ;
V_11 [ V_6 ] = 0LL ;
F_7 ( V_12 [ V_6 ] ) ;
V_12 [ V_6 ] = NULL ;
V_20 -- ;
}
}
if ( V_21 || V_22 )
F_3 ( V_13 , L_6 ) ;
return 0 ;
}
void
F_8 (
const char * V_23 ,
int V_24 ,
struct V_25 * V_13 ,
const char * V_26 ,
int V_27 ,
void * V_28 )
{
if ( V_24 <= V_29 ) {
F_9 ( V_13 , V_30 ,
L_7 ,
V_23 , V_27 , V_26 , V_28 ) ;
F_10 () ;
}
}
void
F_11 (
const char * V_23 ,
int V_24 ,
struct V_25 * V_13 ,
void * V_31 ,
const char * V_26 ,
int V_27 ,
void * V_28 )
{
if ( V_24 <= V_29 )
F_12 ( V_31 , 64 ) ;
F_8 ( V_23 , V_24 , V_13 , V_26 , V_27 , V_28 ) ;
F_13 ( V_13 , L_8 ) ;
}
void
F_14 (
struct V_32 * V_33 )
{
struct V_25 * V_13 = V_33 -> V_34 -> V_35 ;
F_13 ( V_13 , L_9 ,
V_33 -> V_36 == - V_37 ? L_10 : L_11 ,
V_38 , V_33 -> V_39 -> V_40 , V_33 -> V_41 ) ;
F_13 ( V_13 , L_12 ) ;
if ( V_29 >= V_42 ) {
F_13 ( V_13 , L_13 ) ;
F_12 ( F_15 ( V_33 , 0 ) , 64 ) ;
}
if ( V_29 >= V_43 )
F_10 () ;
}
