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
F_4 ( int V_1 , T_2 * V_13 )
{
int V_6 ;
int V_14 ;
T_1 V_7 ;
memcpy ( & V_7 , V_13 -> V_15 , sizeof( V_8 ) ) ;
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
V_14 = strlen ( V_13 -> V_16 ) ;
V_12 [ V_6 ] = F_5 ( V_14 + 1 , V_17 ) ;
strcpy ( V_12 [ V_6 ] , V_13 -> V_16 ) ;
V_18 ++ ;
return 0 ;
}
}
F_3 ( V_13 , L_4 ) ;
return 1 ;
}
int
F_6 ( T_2 * V_13 , int V_19 )
{
T_1 V_7 ;
int V_20 = 0 ;
int V_6 ;
memcpy ( & V_7 , V_13 -> V_15 , sizeof( V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
if ( ( V_7 == 0LL || V_11 [ V_6 ] == V_7 ) &&
V_10 [ V_6 ] != 0 ) {
V_20 = 1 ;
F_3 ( V_13 , L_5 ,
V_10 [ V_6 ] ) ;
V_10 [ V_6 ] = 0 ;
V_11 [ V_6 ] = 0LL ;
F_7 ( V_12 [ V_6 ] ) ;
V_12 [ V_6 ] = NULL ;
V_18 -- ;
}
}
if ( V_19 || V_20 )
F_3 ( V_13 , L_6 ) ;
return 0 ;
}
void
F_8 (
const char * V_21 ,
int V_22 ,
struct V_23 * V_13 ,
const char * V_24 ,
int V_25 ,
void * V_26 )
{
if ( V_22 <= V_27 ) {
F_9 ( V_13 , V_28 ,
L_7 ,
V_21 , V_25 , V_24 , V_26 ) ;
F_10 () ;
}
}
void
F_11 (
const char * V_21 ,
int V_22 ,
struct V_23 * V_13 ,
void * V_29 ,
const char * V_24 ,
int V_25 ,
void * V_26 )
{
if ( V_22 <= V_27 )
F_12 ( V_29 , 64 ) ;
F_8 ( V_21 , V_22 , V_13 , V_24 , V_25 , V_26 ) ;
F_13 ( V_13 , L_8 ) ;
}
void
F_14 (
struct V_30 * V_31 )
{
struct V_23 * V_13 = V_31 -> V_32 -> V_33 ;
F_13 ( V_13 , L_9 ,
V_31 -> V_34 == - V_35 ? L_10 : L_11 ,
V_36 , V_31 -> V_37 -> V_38 , V_31 -> V_39 ) ;
F_13 ( V_13 , L_12 ) ;
if ( V_27 >= V_40 ) {
F_13 ( V_13 , L_13 ) ;
F_12 ( F_15 ( V_31 , 0 ) , 64 ) ;
}
if ( V_27 >= V_41 )
F_10 () ;
}
