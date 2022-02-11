int
F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_5 ;
#define F_2 ( T_1 ) \
do { \
ret = svnic_dev_spec(snic->vdev, \
offsetof(struct vnic_snic_config, m), \
sizeof(c->m), \
&c->m); \
if (ret) { \
SNIC_HOST_ERR(snic->shost, \
"Error getting %s, %d\n", #m, ret); \
return ret; \
} \
} while (0)
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
V_3 -> V_6 = F_3 ( V_17 ,
V_18 ,
F_4 ( V_17 ,
V_19 ,
V_3 -> V_6 ) ) ;
V_3 -> V_6 = F_5 ( V_3 -> V_6 , 16 ) ;
V_3 -> V_7 = F_3 ( V_17 ,
V_20 ,
F_4 ( V_17 ,
V_21 ,
V_3 -> V_7 ) ) ;
V_3 -> V_11 = F_3 ( V_17 ,
V_22 ,
F_4 ( V_17 ,
V_23 ,
V_3 -> V_11 ) ) ;
V_3 -> V_12 = F_3 ( V_17 ,
V_24 ,
V_3 -> V_12 ) ;
V_3 -> V_13 = F_3 ( V_17 ,
V_25 ,
V_3 -> V_13 ) ;
V_3 -> V_14 = F_3 ( V_17 ,
V_26 ,
F_4 ( V_17 ,
V_27 ,
V_3 -> V_14 ) ) ;
V_3 -> V_8 = F_3 ( V_17 , V_28 , V_3 -> V_8 ) ;
F_6 ( L_1 , V_3 -> V_6 ) ;
F_6 ( L_2 ,
V_3 -> V_7 ,
V_3 -> V_8 ) ;
F_6 ( L_3 ,
V_3 -> V_10 ,
V_3 -> V_14 ) ;
F_6 ( L_4 , V_3 -> V_11 ) ;
F_6 ( L_5 ,
V_3 -> V_12 ,
V_3 -> V_13 ) ;
F_6 ( L_6 , V_3 -> V_15 ) ;
F_6 ( L_7 , V_3 -> V_16 ) ;
return 0 ;
}
void
F_7 ( struct V_1 * V_1 )
{
V_1 -> V_29 = F_8 ( V_1 -> V_30 , V_31 ) ;
F_9 ( V_1 -> V_29 == 0 ) ;
V_1 -> V_32 = F_8 ( V_1 -> V_30 , V_33 ) ;
F_9 ( V_1 -> V_32 == 0 ) ;
V_1 -> V_34 = F_8 ( V_1 -> V_30 ,
V_35 ) ;
F_9 ( V_1 -> V_34 == 0 ) ;
}
void
F_10 ( struct V_1 * V_1 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_1 -> V_29 ; V_36 ++ )
F_11 ( & V_1 -> V_37 [ V_36 ] ) ;
for ( V_36 = 0 ; V_36 < V_1 -> V_32 ; V_36 ++ )
F_12 ( & V_1 -> V_38 [ V_36 ] ) ;
for ( V_36 = 0 ; V_36 < V_1 -> V_34 ; V_36 ++ )
F_13 ( & V_1 -> V_39 [ V_36 ] ) ;
}
int
F_14 ( struct V_1 * V_1 )
{
enum V_40 V_41 ;
unsigned int V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_36 ;
int V_5 ;
V_41 = F_15 ( V_1 -> V_30 ) ;
F_6 ( L_8 ,
( ( V_41 == V_46 ) ?
L_9 :
( ( V_41 == V_47 ) ?
L_10 :
( ( V_41 == V_48 ) ?
L_11 : L_12 ) ) ) ) ;
F_9 ( V_41 != V_48 ) ;
F_6 ( L_13 , V_1 -> V_29 ,
V_1 -> V_32 ,
V_1 -> V_34 ) ;
for ( V_36 = 0 ; V_36 < V_1 -> V_29 ; V_36 ++ ) {
V_5 = F_16 ( V_1 -> V_30 ,
& V_1 -> V_37 [ V_36 ] ,
V_36 ,
V_1 -> V_4 . V_6 ,
sizeof( struct V_49 ) ) ;
if ( V_5 )
goto V_50;
}
for ( V_36 = 0 ; V_36 < V_1 -> V_29 ; V_36 ++ ) {
V_5 = F_17 ( V_1 -> V_30 ,
& V_1 -> V_38 [ V_36 ] ,
V_36 ,
V_1 -> V_4 . V_6 ,
sizeof( struct V_51 ) ) ;
if ( V_5 )
goto V_50;
}
F_9 ( V_1 -> V_32 != 2 * V_1 -> V_29 ) ;
for ( V_36 = V_1 -> V_29 ; V_36 < V_1 -> V_32 ; V_36 ++ ) {
V_5 = F_17 ( V_1 -> V_30 ,
& V_1 -> V_38 [ V_36 ] ,
V_36 ,
( V_1 -> V_4 . V_6 * 3 ) ,
sizeof( struct V_52 ) ) ;
if ( V_5 )
goto V_50;
}
for ( V_36 = 0 ; V_36 < V_1 -> V_34 ; V_36 ++ ) {
V_5 = F_18 ( V_1 -> V_30 , & V_1 -> V_39 [ V_36 ] , V_36 ) ;
if ( V_5 )
goto V_50;
}
V_44 = 1 ;
V_45 = V_1 -> V_45 ;
for ( V_36 = 0 ; V_36 < V_1 -> V_29 ; V_36 ++ ) {
F_19 ( & V_1 -> V_37 [ V_36 ] ,
V_36 ,
V_44 ,
V_45 ) ;
}
for ( V_36 = 0 ; V_36 < V_1 -> V_32 ; V_36 ++ ) {
V_43 = V_36 ;
F_20 ( & V_1 -> V_38 [ V_36 ] ,
0 ,
1 ,
0 ,
0 ,
1 ,
1 ,
1 ,
0 ,
V_43 ,
0 ) ;
}
F_9 ( V_41 != V_48 ) ;
V_42 = 1 ;
for ( V_36 = 0 ; V_36 < V_1 -> V_34 ; V_36 ++ ) {
F_21 ( & V_1 -> V_39 [ V_36 ] ,
V_1 -> V_4 . V_8 ,
V_1 -> V_4 . V_9 ,
V_42 ) ;
}
V_5 = F_22 ( V_1 -> V_30 , & V_1 -> V_53 ) ;
if ( V_5 ) {
F_23 ( V_1 -> V_54 ,
L_14 ,
V_5 ) ;
goto V_50;
}
F_24 ( V_1 -> V_30 ) ;
V_5 = 0 ;
return V_5 ;
V_50:
F_10 ( V_1 ) ;
return V_5 ;
}
void
F_25 ( struct V_1 * V_1 )
{
unsigned int V_36 ;
V_17 V_55 ;
for ( V_36 = 0 ; V_36 < V_1 -> V_29 ; V_36 ++ ) {
V_55 = F_26 ( & V_1 -> V_37 [ V_36 ] . V_56 -> V_57 ) ;
if ( V_55 )
F_23 ( V_1 -> V_54 ,
L_15 ,
V_36 ,
V_55 ) ;
}
}
