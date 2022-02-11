int F_1 ( struct V_1 * V_2 , void * V_3 ,
unsigned long V_4 )
{
int V_5 , V_6 = - V_7 ;
struct V_8 * V_9 ;
if ( V_2 -> type == V_10 )
return - V_11 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_12 ) ; V_5 ++ ) {
V_9 = V_12 [ V_5 ] ;
if ( ! V_9 || ! V_9 -> V_13 )
continue;
V_6 = V_9 -> V_13 ( V_3 , V_4 ) ;
if ( ! V_6 ) {
V_2 -> V_9 = V_9 ;
return V_6 ;
}
}
return V_6 ;
}
void * F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_9 -> V_14 )
return F_4 ( - V_7 ) ;
return V_2 -> V_9 -> V_14 ( V_2 , V_2 -> V_15 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_2 -> V_18 , V_2 -> V_19 ,
V_2 -> V_20 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_9 -> V_21 )
return 0 ;
return V_2 -> V_9 -> V_21 ( V_2 -> V_22 ) ;
}
int F_6 ( struct V_23 * V_24 , int (* F_7)( T_1 , T_1 , void * ) )
{
int V_6 = 0 ;
T_1 V_5 ;
T_2 V_25 , V_26 ;
if ( V_24 -> V_27 ) {
F_8 (i, NUMA_NO_NODE, 0 ,
&mstart, &mend, NULL) {
V_6 = F_7 ( V_25 , V_26 - 1 , V_24 ) ;
if ( V_6 )
break;
}
} else {
F_9 (i, NUMA_NO_NODE, 0 , &mstart, &mend,
NULL) {
V_6 = F_7 ( V_25 , V_26 - 1 , V_24 ) ;
if ( V_6 )
break;
}
}
return V_6 ;
}
int F_10 ( struct V_1 * V_2 , const void * V_28 ,
const void * V_29 , unsigned long V_30 ,
unsigned long V_31 )
{
unsigned int * V_32 , V_33 ;
int V_6 ;
V_32 = F_11 ( V_34 , V_35 ) ;
if ( ! V_32 )
return - V_36 ;
V_6 = F_12 ( V_2 , L_1 ,
V_32 , V_34 ,
true ) ;
if ( V_6 ) {
F_13 ( V_32 ) ;
return V_6 ;
}
V_33 = V_32 [ 0 ] ;
memcpy ( V_32 , V_28 , V_34 ) ;
V_32 [ 0 ] = V_33 ;
V_6 = F_12 ( V_2 , L_1 ,
V_32 , V_34 ,
false ) ;
F_13 ( V_32 ) ;
V_6 = F_12 ( V_2 , L_2 , & V_30 ,
sizeof( V_30 ) , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_12 ( V_2 , L_3 , & V_31 ,
sizeof( V_31 ) , false ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
int F_14 ( void * V_29 , unsigned long V_37 , unsigned long V_38 )
{
int V_5 , V_6 , V_39 = F_15 ( V_29 ) ;
for ( V_5 = 0 ; V_5 < V_39 ; V_5 ++ ) {
T_3 V_40 , V_41 ;
V_6 = F_16 ( V_29 , V_5 , & V_40 , & V_41 ) ;
if ( V_6 ) {
F_17 ( L_4 ) ;
return - V_42 ;
}
if ( V_40 == V_37 && V_41 == V_38 ) {
V_6 = F_18 ( V_29 , V_5 ) ;
if ( V_6 ) {
F_17 ( L_5 ) ;
return - V_42 ;
}
return 0 ;
}
}
return - V_43 ;
}
int F_19 ( const struct V_1 * V_2 , void * V_29 ,
unsigned long V_44 , unsigned long V_45 ,
const char * V_46 )
{
int V_6 , V_47 ;
const void * V_48 ;
V_6 = F_14 ( V_29 , F_20 ( V_49 ) ,
F_21 ( V_49 ) ) ;
if ( V_6 == 0 )
F_22 ( L_6 ) ;
else if ( V_6 != - V_43 )
return V_6 ;
V_47 = F_23 ( V_29 , L_7 ) ;
if ( V_47 == - V_50 ) {
V_47 = F_24 ( V_29 , F_23 ( V_29 , L_8 ) ,
L_9 ) ;
if ( V_47 < 0 ) {
F_17 ( L_10 ) ;
return - V_42 ;
}
} else if ( V_47 < 0 ) {
F_17 ( L_11 ) ;
return - V_42 ;
}
V_48 = F_25 ( V_29 , V_47 , L_12 , NULL ) ;
if ( V_48 ) {
T_3 V_51 , V_52 , V_53 ;
V_51 = F_26 ( * ( ( const V_54 * ) V_48 ) ) ;
V_48 = F_25 ( V_29 , V_47 , L_13 , NULL ) ;
if ( ! V_48 ) {
F_17 ( L_4 ) ;
return - V_42 ;
}
V_52 = F_26 ( * ( ( const V_54 * ) V_48 ) ) ;
V_53 = V_52 - V_51 ;
V_6 = F_14 ( V_29 , V_51 , V_53 ) ;
if ( V_6 == - V_43 )
V_6 = F_14 ( V_29 , V_51 ,
F_27 ( V_53 , V_55 ) ) ;
if ( V_6 == 0 )
F_22 ( L_14 ) ;
else if ( V_6 != - V_43 )
return V_6 ;
if ( V_45 == 0 ) {
V_6 = F_28 ( V_29 , V_47 ,
L_12 ) ;
if ( V_6 ) {
F_17 ( L_15 ) ;
return - V_42 ;
}
V_6 = F_28 ( V_29 , V_47 , L_13 ) ;
if ( V_6 ) {
F_17 ( L_16 ) ;
return - V_42 ;
}
}
}
if ( V_45 ) {
V_6 = F_29 ( V_29 , V_47 ,
L_12 ,
V_44 ) ;
if ( V_6 < 0 ) {
F_17 ( L_17 ) ;
return - V_42 ;
}
V_6 = F_29 ( V_29 , V_47 , L_13 ,
V_44 + V_45 ) ;
if ( V_6 < 0 ) {
F_17 ( L_17 ) ;
return - V_42 ;
}
V_6 = F_30 ( V_29 , V_44 , V_45 ) ;
if ( V_6 ) {
F_17 ( L_18 ,
F_31 ( V_6 ) ) ;
return - V_42 ;
}
}
if ( V_46 != NULL ) {
V_6 = F_32 ( V_29 , V_47 , L_19 , V_46 ) ;
if ( V_6 < 0 ) {
F_17 ( L_17 ) ;
return - V_42 ;
}
} else {
V_6 = F_28 ( V_29 , V_47 , L_19 ) ;
if ( V_6 && V_6 != - V_50 ) {
F_17 ( L_20 ) ;
return - V_42 ;
}
}
V_6 = F_33 ( V_2 , V_29 , V_47 ) ;
if ( V_6 ) {
F_17 ( L_17 ) ;
return V_6 ;
}
V_6 = F_34 ( V_29 , V_47 , L_21 , NULL , 0 ) ;
if ( V_6 ) {
F_17 ( L_17 ) ;
return - V_42 ;
}
return 0 ;
}
