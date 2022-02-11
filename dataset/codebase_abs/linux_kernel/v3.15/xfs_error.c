int
F_1 ( int V_1 )
{
int V_2 ;
if ( ! V_1 )
return 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] == 0 )
break;
if ( V_1 != V_4 [ V_2 ] )
continue;
F_2 ( NULL , L_1 , V_5 , V_1 ) ;
F_3 () ;
break;
}
return V_1 ;
}
int
F_4 ( int V_6 , int * V_7 , char * V_8 ,
int line , char * V_9 , unsigned long V_10 )
{
int V_2 ;
T_1 V_11 ;
if ( F_5 () % V_10 )
return 0 ;
memcpy ( & V_11 , V_7 , sizeof( V_12 ) ) ;
for ( V_2 = 0 ; V_2 < V_13 ; V_2 ++ ) {
if ( V_14 [ V_2 ] == V_6 && V_15 [ V_2 ] == V_11 ) {
F_6 ( NULL ,
L_2 ,
V_8 , V_9 , line , V_16 [ V_2 ] ) ;
return 1 ;
}
}
return 0 ;
}
int
F_7 ( int V_6 , T_2 * V_17 )
{
int V_2 ;
int V_18 ;
T_1 V_11 ;
memcpy ( & V_11 , V_17 -> V_19 , sizeof( V_12 ) ) ;
for ( V_2 = 0 ; V_2 < V_13 ; V_2 ++ ) {
if ( V_15 [ V_2 ] == V_11 && V_14 [ V_2 ] == V_6 ) {
F_6 ( V_17 , L_3 , V_6 ) ;
return 0 ;
}
}
for ( V_2 = 0 ; V_2 < V_13 ; V_2 ++ ) {
if ( V_14 [ V_2 ] == 0 ) {
F_6 ( V_17 , L_4 ,
V_6 ) ;
V_14 [ V_2 ] = V_6 ;
V_15 [ V_2 ] = V_11 ;
V_18 = strlen ( V_17 -> V_20 ) ;
V_16 [ V_2 ] = F_8 ( V_18 + 1 , V_21 ) ;
strcpy ( V_16 [ V_2 ] , V_17 -> V_20 ) ;
V_22 ++ ;
return 0 ;
}
}
F_6 ( V_17 , L_5 ) ;
return 1 ;
}
int
F_9 ( T_2 * V_17 , int V_23 )
{
T_1 V_11 ;
int V_24 = 0 ;
int V_2 ;
memcpy ( & V_11 , V_17 -> V_19 , sizeof( V_12 ) ) ;
for ( V_2 = 0 ; V_2 < V_13 ; V_2 ++ ) {
if ( ( V_11 == 0LL || V_15 [ V_2 ] == V_11 ) &&
V_14 [ V_2 ] != 0 ) {
V_24 = 1 ;
F_6 ( V_17 , L_6 ,
V_14 [ V_2 ] ) ;
V_14 [ V_2 ] = 0 ;
V_15 [ V_2 ] = 0LL ;
F_10 ( V_16 [ V_2 ] ) ;
V_16 [ V_2 ] = NULL ;
V_22 -- ;
}
}
if ( V_23 || V_24 )
F_6 ( V_17 , L_7 ) ;
return 0 ;
}
void
F_11 (
const char * V_25 ,
int V_26 ,
struct V_27 * V_17 ,
const char * V_28 ,
int V_29 ,
T_3 * V_30 )
{
if ( V_26 <= V_31 ) {
F_12 ( V_17 , V_32 ,
L_8 ,
V_25 , V_29 , V_28 , V_30 ) ;
F_13 () ;
}
}
void
F_14 (
const char * V_25 ,
int V_26 ,
struct V_27 * V_17 ,
void * V_33 ,
const char * V_28 ,
int V_29 ,
T_3 * V_30 )
{
if ( V_26 <= V_31 )
F_15 ( V_33 , 64 ) ;
F_11 ( V_25 , V_26 , V_17 , V_28 , V_29 , V_30 ) ;
F_16 ( V_17 , L_9 ) ;
}
void
F_17 (
struct V_34 * V_35 )
{
struct V_27 * V_17 = V_35 -> V_36 -> V_37 ;
F_16 ( V_17 , L_10 ,
V_35 -> V_38 == V_39 ? L_11 : L_12 ,
V_40 , V_35 -> V_41 ) ;
F_16 ( V_17 , L_13 ) ;
if ( V_31 >= V_42 ) {
F_16 ( V_17 , L_14 ) ;
F_15 ( F_18 ( V_35 , 0 ) , 64 ) ;
}
if ( V_31 >= V_43 )
F_13 () ;
}
