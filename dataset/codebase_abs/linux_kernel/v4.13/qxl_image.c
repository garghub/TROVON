static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( sizeof( struct V_8 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_10 = F_3 ( V_2 , V_4 , V_7 , & V_9 -> V_13 ) ;
if ( V_10 ) {
F_4 ( V_9 ) ;
return V_10 ;
}
F_5 ( & V_9 -> V_14 , & V_6 -> V_15 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_16 ,
int V_17 , int V_18 )
{
struct V_5 * V_6 ;
int V_10 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
F_7 ( & V_6 -> V_15 ) ;
V_10 = F_3 ( V_2 , V_4 , sizeof( struct V_19 ) , & V_6 -> V_13 ) ;
if ( V_10 ) {
F_4 ( V_6 ) ;
return V_10 ;
}
V_10 = F_1 ( V_2 , V_4 , V_6 , sizeof( struct V_20 ) + V_18 * V_17 ) ;
if ( V_10 ) {
F_8 ( & V_6 -> V_13 ) ;
F_4 ( V_6 ) ;
return V_10 ;
}
* V_16 = V_6 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , struct V_5 * V_21 )
{
struct V_8 * V_9 , * V_22 ;
F_10 (chunk, tmp, &dimage->chunk_list, head) {
F_8 ( & V_9 -> V_13 ) ;
F_4 ( V_9 ) ;
}
F_8 ( & V_21 -> V_13 ) ;
F_4 ( V_21 ) ;
}
static int
F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_21 ,
const T_1 * V_23 ,
int V_24 , int V_17 ,
int V_25 , unsigned int V_26 ,
int V_18 )
{
struct V_8 * V_27 ;
struct V_19 * V_6 ;
struct V_20 * V_9 ;
int V_28 ;
int V_29 ;
int V_30 = V_24 * V_25 / 8 ;
struct V_31 * V_32 , * V_33 ;
void * V_34 ;
V_27 = F_12 ( & V_21 -> V_15 , struct V_8 , V_14 ) ;
V_32 = V_27 -> V_13 ;
V_29 = V_18 ;
V_34 = F_13 ( V_2 , V_32 , 0 ) ;
V_9 = V_34 ;
V_9 -> V_35 = V_17 * V_29 ;
V_9 -> V_36 = 0 ;
V_9 -> V_37 = 0 ;
F_14 ( V_2 , V_32 , V_34 ) ;
{
void * V_38 , * V_39 ;
int V_40 ;
int V_41 ;
int V_42 ;
if ( V_18 == V_30 && V_29 == V_18 ) {
V_40 = V_30 * V_17 ;
V_41 = 0 ;
V_39 = ( void * ) V_23 ;
while ( V_40 > 0 ) {
V_34 = F_13 ( V_2 , V_32 , V_41 << V_43 ) ;
if ( V_41 == 0 ) {
V_9 = V_34 ;
V_38 = V_9 -> V_23 ;
V_42 = V_44 - F_15 ( struct V_20 , V_23 ) ;
} else {
V_38 = V_34 ;
V_42 = V_44 ;
}
V_42 = F_16 ( V_42 , V_40 ) ;
memcpy ( V_38 , V_39 , V_42 ) ;
F_14 ( V_2 , V_32 , V_34 ) ;
V_39 += V_42 ;
V_40 -= V_42 ;
V_41 ++ ;
}
} else {
unsigned V_45 , V_46 , V_47 ;
for ( V_28 = 0 ; V_28 < V_17 ; ++ V_28 ) {
V_39 = ( void * ) V_23 + V_28 * V_18 ;
V_40 = V_30 ;
V_47 = F_15 ( struct V_20 , V_23 ) + V_28 * V_29 ;
while ( V_40 > 0 ) {
V_45 = V_47 & V_48 ;
V_46 = F_17 ( V_47 ) ;
V_42 = F_16 ( ( int ) ( V_44 - V_46 ) , V_40 ) ;
V_34 = F_13 ( V_2 , V_32 , V_45 ) ;
V_38 = V_34 + V_46 ;
memcpy ( V_38 , V_39 , V_42 ) ;
F_14 ( V_2 , V_32 , V_34 ) ;
V_40 -= V_42 ;
V_39 += V_42 ;
V_47 += V_42 ;
}
}
}
}
F_18 ( V_32 ) ;
V_33 = V_21 -> V_13 ;
V_34 = F_13 ( V_2 , V_33 , 0 ) ;
V_6 = V_34 ;
V_6 -> V_49 . V_50 = 0 ;
V_6 -> V_49 . type = V_51 ;
V_6 -> V_49 . V_52 = 0 ;
V_6 -> V_49 . V_24 = V_24 ;
V_6 -> V_49 . V_17 = V_17 ;
switch ( V_25 ) {
case 1 :
V_6 -> V_53 . V_54 . V_55 = V_56 ;
break;
case 24 :
V_6 -> V_53 . V_54 . V_55 = V_57 ;
break;
case 32 :
V_6 -> V_53 . V_54 . V_55 = V_58 ;
break;
default:
F_19 ( L_1 ) ;
return - V_59 ;
}
V_6 -> V_53 . V_54 . V_52 = V_60 ;
V_6 -> V_53 . V_54 . V_61 = V_24 ;
V_6 -> V_53 . V_54 . V_62 = V_17 ;
V_6 -> V_53 . V_54 . V_18 = V_29 ;
V_6 -> V_53 . V_54 . V_63 = 0 ;
V_6 -> V_53 . V_54 . V_23 = F_20 ( V_2 , V_32 , 0 ) ;
F_14 ( V_2 , V_33 , V_34 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_21 ,
const T_1 * V_23 ,
int V_61 , int V_62 , int V_24 , int V_17 ,
int V_25 , int V_18 )
{
V_23 += V_62 * V_18 + V_61 * ( V_25 / 8 ) ;
return F_11 ( V_2 , V_4 , V_21 , V_23 ,
V_24 , V_17 , V_25 , 0 , V_18 ) ;
}
