static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 , * V_11 ;
unsigned long V_12 ;
V_12 = V_6 * V_3 -> V_13 ;
V_8 -> V_14 = V_3 -> V_14 ;
V_8 -> V_15 = V_3 -> V_15 ;
if ( V_8 -> V_14 ) {
V_8 -> V_16 = * ( unsigned char * ) ( V_5 -> V_17 -> V_18 + V_12 +
V_3 -> V_16 ) ;
V_8 -> V_19 = * ( unsigned char * ) ( V_5 -> V_17 -> V_18 + V_12 +
V_3 -> V_19 ) ;
}
if ( V_3 -> V_20 ) {
unsigned short V_20 ;
V_20 = * ( unsigned short * ) ( V_5 -> V_17 -> V_18 + V_12 +
V_3 -> V_20 ) ;
if ( V_20 == V_21 )
V_8 -> V_22 = true ;
}
V_10 = F_2 ( V_5 , V_12 + V_3 -> V_23 ) ;
if ( ! V_10 ) {
F_3 ( L_1 , V_5 , V_12 + V_3 -> V_23 ) ;
return - 1 ;
}
if ( V_10 -> V_24 -> type != V_25 ) {
F_3 ( L_2 ,
V_5 , V_12 + V_3 -> V_23 , V_10 -> V_24 -> V_26 ) ;
return - 1 ;
}
V_8 -> V_27 = V_10 -> V_24 -> V_5 ;
V_8 -> V_28 = V_10 -> V_29 ;
if ( ! V_3 -> V_14 || V_8 -> V_19 ) {
V_11 = F_2 ( V_5 , V_12 + V_3 -> V_30 ) ;
if ( ! V_11 ) {
F_3 ( L_3 ,
V_5 , V_12 + V_3 -> V_30 ) ;
return - 1 ;
}
V_8 -> V_31 = V_11 -> V_24 -> V_5 ;
V_8 -> V_32 = ( unsigned int ) V_11 -> V_29 ;
if ( V_8 -> V_32 >= 0x7ffffff0 )
V_8 -> V_32 -= 0x7ffffff0 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
unsigned int V_35 ;
struct V_7 * V_8 ;
int V_6 , V_36 ;
F_5 ( V_34 ) ;
for ( V_3 = V_37 ; V_3 -> V_5 ; V_3 ++ ) {
V_5 = F_6 ( V_1 , V_3 -> V_5 ) ;
if ( ! V_5 )
continue;
if ( V_5 -> V_38 % V_3 -> V_13 != 0 ) {
F_7 ( L_4 ,
V_5 -> V_26 , V_3 -> V_13 ) ;
return - 1 ;
}
V_35 = V_5 -> V_38 / V_3 -> V_13 ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ ) {
V_8 = malloc ( sizeof( * V_8 ) ) ;
if ( ! V_8 ) {
F_7 ( L_5 ) ;
return - 1 ;
}
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_36 = F_1 ( V_1 , V_3 , V_5 , V_6 , V_8 ) ;
if ( V_36 )
return V_36 ;
F_8 ( & V_8 -> V_39 , V_34 ) ;
}
}
return 0 ;
}
