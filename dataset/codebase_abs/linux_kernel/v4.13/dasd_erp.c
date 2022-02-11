struct V_1 *
F_1 ( char * V_2 , int V_3 , int V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 ;
struct V_1 * V_8 ;
char * V_9 ;
int V_10 ;
F_2 ( V_2 == NULL || V_4 > V_11 ||
( V_3 * sizeof( struct V_12 ) ) > V_11 ) ;
V_10 = ( sizeof( struct V_1 ) + 7L ) & - 8L ;
if ( V_3 > 0 )
V_10 += V_3 * sizeof( struct V_12 ) ;
if ( V_4 > 0 )
V_10 += V_4 ;
F_3 ( & V_6 -> V_13 , V_7 ) ;
V_8 = (struct V_1 * )
F_4 ( & V_6 -> V_14 , V_10 ) ;
F_5 ( & V_6 -> V_13 , V_7 ) ;
if ( V_8 == NULL )
return F_6 ( - V_15 ) ;
memset ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_7 ( & V_8 -> V_16 ) ;
F_7 ( & V_8 -> V_17 ) ;
V_9 = ( char * ) V_8 + ( ( sizeof( struct V_1 ) + 7L ) & - 8L ) ;
V_8 -> V_18 = NULL ;
if ( V_3 > 0 ) {
V_8 -> V_18 = (struct V_12 * ) V_9 ;
V_9 += V_3 * sizeof( struct V_12 ) ;
memset ( V_8 -> V_18 , 0 , V_3 * sizeof( struct V_12 ) ) ;
}
V_8 -> V_9 = NULL ;
if ( V_4 > 0 ) {
V_8 -> V_9 = V_9 ;
memset ( V_8 -> V_9 , 0 , V_4 ) ;
}
strncpy ( ( char * ) & V_8 -> V_2 , V_2 , 4 ) ;
F_8 ( ( char * ) & V_8 -> V_2 , 4 ) ;
F_9 ( V_19 , & V_8 -> V_7 ) ;
F_10 ( V_6 ) ;
return V_8 ;
}
void
F_11 ( struct V_1 * V_8 , struct V_5 * V_6 )
{
unsigned long V_7 ;
F_3 ( & V_6 -> V_13 , V_7 ) ;
F_12 ( & V_6 -> V_14 , V_8 ) ;
F_5 ( & V_6 -> V_13 , V_7 ) ;
F_13 ( & V_6 -> V_20 ) ;
}
struct V_1 *
F_14 ( struct V_1 * V_8 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_8 -> V_22 > 0 ) {
F_15 ( V_23 , V_6 ,
L_1 ,
V_8 -> V_22 ) ;
if ( ! F_16 ( V_24 , & V_8 -> V_7 ) )
V_8 -> V_25 = F_17 ( V_6 ) ;
V_8 -> V_26 = V_27 ;
} else {
F_18 ( L_2 ,
F_19 ( & V_6 -> V_28 -> V_29 ) ) ;
V_8 -> V_26 = V_30 ;
V_8 -> V_31 = F_20 () ;
}
return V_8 ;
}
struct V_1 * F_21 ( struct V_1 * V_8 )
{
int V_32 ;
unsigned long long V_33 , V_31 ;
struct V_5 * V_21 ;
F_2 ( V_8 -> V_34 == NULL || V_8 -> V_35 == NULL ) ;
V_32 = V_8 -> V_26 == V_36 ;
V_33 = V_8 -> V_33 ;
V_31 = V_8 -> V_31 ;
V_21 = V_8 -> V_21 ;
while ( V_8 -> V_34 != NULL ) {
struct V_1 * V_34 ;
V_34 = V_8 -> V_34 ;
F_22 ( & V_8 -> V_17 ) ;
F_11 ( V_8 , V_8 -> V_37 ) ;
V_8 = V_34 ;
}
V_8 -> V_33 = V_33 ;
V_8 -> V_31 = V_31 ;
V_8 -> V_21 = V_21 ;
if ( V_32 )
V_8 -> V_26 = V_36 ;
else {
V_8 -> V_26 = V_30 ;
V_8 -> V_31 = F_20 () ;
}
return V_8 ;
}
void
F_23 ( struct V_1 * V_8 , struct V_38 * V_38 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_8 -> V_39 == - V_40 ) {
F_24 ( & V_6 -> V_28 -> V_29 ,
L_3 , V_8 ) ;
return;
}
if ( V_8 -> V_39 == - V_41 ) {
F_24 ( & V_6 -> V_28 -> V_29 ,
L_4 , V_8 ) ;
return;
}
if ( V_6 -> V_42 && V_6 -> V_42 -> V_43 )
V_6 -> V_42 -> V_43 ( V_6 , V_8 , V_38 ) ;
}
void
F_25 ( struct V_1 * V_8 , struct V_38 * V_38 )
{
struct V_5 * V_6 ;
V_6 = V_8 -> V_21 ;
if ( V_6 -> V_42 && V_6 -> V_42 -> V_44 )
V_6 -> V_42 -> V_44 ( V_6 , V_38 , L_5 ) ;
}
