static T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return 0 ;
return ( V_2 -> V_3 -> V_4 >> 9 ) - 1ULL ;
}
static T_2 F_2 ( struct V_5 * V_6 , T_1 V_7 , T_3 * V_8 ,
T_2 V_9 )
{
T_2 V_10 = 0 ;
if ( ! V_8 || V_7 + V_9 / 512 > F_1 ( V_6 -> V_2 ) )
return 0 ;
while ( V_9 ) {
int V_11 = 512 ;
T_4 V_12 ;
unsigned char * V_13 = F_3 ( V_6 , V_7 ++ , & V_12 ) ;
if ( ! V_13 )
break;
if ( V_11 > V_9 )
V_11 = V_9 ;
memcpy ( V_8 , V_13 , V_11 ) ;
F_4 ( V_12 ) ;
V_8 += V_11 ;
V_10 += V_11 ;
V_9 -= V_11 ;
}
return V_10 ;
}
static struct V_14 * F_5 ( struct V_5 * V_6 , T_5 V_7 )
{
T_2 V_9 = sizeof( struct V_14 ) ;
struct V_14 * V_15 ;
V_15 = F_6 ( V_9 , V_16 ) ;
if ( ! V_15 )
return NULL ;
if ( F_2 ( V_6 , V_7 , ( T_3 * ) V_15 , V_9 ) < V_9 ) {
F_7 ( V_15 ) ;
return NULL ;
}
return V_15 ;
}
static struct V_17 * F_8 ( struct V_5 * V_6 , T_5 V_7 )
{
T_2 V_9 = sizeof( struct V_17 ) * V_18 ;
struct V_17 * V_15 ;
V_15 = F_6 ( V_9 , V_16 ) ;
if ( ! V_15 )
return NULL ;
if ( F_2 ( V_6 , V_7 , ( T_3 * ) V_15 , V_9 ) < V_9 ) {
F_7 ( V_15 ) ;
return NULL ;
}
return V_15 ;
}
int F_9 ( struct V_5 * V_6 )
{
int V_19 = 0 ;
T_4 V_12 ;
unsigned char * V_20 ;
T_5 V_21 ;
T_5 V_22 = 0 ;
T_5 V_23 = 0 ;
T_5 V_24 = 0 ;
int V_25 = 0 ;
struct V_14 * V_14 ;
struct V_26 {
unsigned short V_27 ;
unsigned short V_28 ;
unsigned char V_29 ;
} * V_30 ;
struct V_17 * V_31 = NULL ;
V_20 = F_3 ( V_6 , 7 , & V_12 ) ;
if ( V_20 ) {
struct V_32 * V_15 = (struct V_32 * ) V_20 ;
T_6 V_33 = F_10 ( V_15 -> V_34 ) ;
char V_35 [ 64 ] ;
if ( V_33 == 1 ) {
int V_36 = F_10 ( V_15 -> V_37 ) ;
V_21 = 1 << V_36 ;
V_22 = V_21 / 512 ;
snprintf ( V_35 , sizeof( V_35 ) ,
L_1 ,
V_33 ) ;
V_24 = F_11 ( V_15 -> V_24 ) ;
V_23 = F_11 ( V_15 -> V_38 [ 0 ] ) ;
} else {
snprintf ( V_35 , sizeof( V_35 ) ,
L_2 ,
V_33 ) ;
}
F_12 ( V_6 -> V_39 , V_35 , V_40 ) ;
F_4 ( V_12 ) ;
}
if ( V_23 && ( V_20 = F_3 ( V_6 , V_23 , & V_12 ) ) ) {
struct V_41 * V_15 = (struct V_41 * ) V_20 ;
V_25 = F_10 ( V_15 -> V_25 ) ;
F_4 ( V_12 ) ;
}
V_30 = F_13 ( V_6 -> V_42 , sizeof( struct V_26 ) , V_16 ) ;
if ( ! V_30 )
return 0 ;
if ( V_25 && ( V_20 = F_3 ( V_6 , V_23 + 1 , & V_12 ) ) ) {
struct V_43 * V_15 = (struct V_43 * ) V_20 ;
int V_44 ;
V_31 = F_8 ( V_6 , V_23 + V_24 - 33 ) ;
if ( V_31 ) {
int V_45 = 0 ;
for ( V_44 = 0 ; V_45 < V_25 && V_44 < V_6 -> V_42 ; V_44 += 1 ) {
V_30 [ V_44 ] . V_27 = F_10 ( V_15 [ V_44 ] . V_46 ) ;
if ( V_30 [ V_44 ] . V_27 )
V_45 += 1 ;
}
}
F_4 ( V_12 ) ;
}
V_14 = F_5 ( V_6 , V_23 + 17 ) ;
if ( V_14 ) {
int V_47 = F_10 ( V_14 -> V_48 ) ;
int V_49 = F_11 ( V_14 -> V_49 ) ;
int V_44 ;
int V_50 = - 1 ;
int V_51 = 1 ;
int V_52 ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 += 1 ) {
struct V_53 * V_15 = V_14 -> V_53 + V_44 ;
unsigned int V_54 ;
V_52 = F_10 ( V_15 -> V_52 ) ;
if ( ! V_52 ) {
V_51 = 1 ;
continue;
}
V_54 = F_10 ( V_15 -> V_54 ) - 1 ;
if ( V_54 >= V_6 -> V_42 ) {
V_50 = - 1 ;
continue;
}
V_30 [ V_54 ] . V_28 += 1 ;
if ( V_52 == 1 ) {
V_50 = V_54 ;
V_51 = 1 ;
} else if ( V_54 != V_50 || V_52 != V_51 ) {
V_51 = 1 ;
continue;
}
if ( V_52 == V_30 [ V_54 ] . V_27 ) {
char V_35 [ 70 ] ;
F_14 ( V_6 , V_54 + 1 ,
( V_44 + 1 - V_52 ) * V_22 + V_49 ,
V_30 [ V_54 ] . V_27 * V_22 ) ;
snprintf ( V_35 , sizeof( V_35 ) , L_3 ,
V_31 [ V_54 ] . V_55 ) ;
F_12 ( V_6 -> V_39 , V_35 , V_40 ) ;
V_30 [ V_54 ] . V_29 = 1 ;
V_19 = 1 ;
V_51 = 1 ;
} else
V_51 += 1 ;
}
for ( V_44 = 0 ; V_44 < V_6 -> V_42 ; V_44 += 1 )
if ( V_30 [ V_44 ] . V_28 && ! V_30 [ V_44 ] . V_29 )
F_15 ( L_4
L_5 ,
V_31 [ V_44 ] . V_55 , V_30 [ V_44 ] . V_28 ) ;
F_7 ( V_14 ) ;
}
F_7 ( V_31 ) ;
F_7 ( V_30 ) ;
return V_19 ;
}
