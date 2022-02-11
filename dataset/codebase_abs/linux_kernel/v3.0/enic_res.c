int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 -> V_6 , V_1 -> V_7 ) ;
if ( V_5 ) {
F_3 ( F_4 ( V_1 ) ,
L_1 , V_5 ) ;
return V_5 ;
}
#define F_5 ( T_1 ) \
do { \
err = vnic_dev_spec(enic->vdev, \
offsetof(struct vnic_enet_config, m), \
sizeof(c->m), &c->m); \
if (err) { \
dev_err(enic_get_dev(enic), \
"Error getting %s, %d\n", #m, err); \
return err; \
} \
} while (0)
F_5 ( V_8 ) ;
F_5 ( V_9 ) ;
F_5 ( V_10 ) ;
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
V_3 -> V_9 =
F_6 ( V_16 , V_17 ,
F_7 ( V_16 , V_18 ,
V_3 -> V_9 ) ) ;
V_3 -> V_9 &= 0xffffffe0 ;
V_3 -> V_10 =
F_6 ( V_16 , V_19 ,
F_7 ( V_16 , V_20 ,
V_3 -> V_10 ) ) ;
V_3 -> V_10 &= 0xffffffe0 ;
if ( V_3 -> V_11 == 0 )
V_3 -> V_11 = 1500 ;
V_3 -> V_11 = F_6 ( V_21 , V_22 ,
F_7 ( V_21 , V_23 ,
V_3 -> V_11 ) ) ;
V_3 -> V_14 = F_6 ( V_16 ,
F_8 ( V_24 ) ,
V_3 -> V_14 ) ;
F_9 ( F_4 ( V_1 ) ,
L_2 ,
V_1 -> V_7 , V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ) ;
F_9 ( F_4 ( V_1 ) , L_3
L_4 ,
F_10 ( V_1 , V_25 ) , F_10 ( V_1 , V_26 ) ,
F_10 ( V_1 , V_27 ) ,
V_3 -> V_14 , F_10 ( V_1 , V_28 ) ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 , V_21 V_29 )
{
T_2 V_30 = V_29 , V_31 = 0 ;
int V_32 = 1000 ;
int V_5 ;
V_5 = F_12 ( V_1 -> V_6 , V_33 , & V_30 , & V_31 , V_32 ) ;
if ( V_5 )
F_3 ( F_4 ( V_1 ) , L_5 , V_5 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_1 , V_21 V_29 )
{
T_2 V_30 = V_29 , V_31 = 0 ;
int V_32 = 1000 ;
int V_5 ;
V_5 = F_12 ( V_1 -> V_6 , V_34 , & V_30 , & V_31 , V_32 ) ;
if ( V_5 )
F_3 ( F_4 ( V_1 ) , L_6 , V_5 ) ;
return V_5 ;
}
int F_14 ( struct V_1 * V_1 , T_3 V_35 , T_3 V_36 ,
T_3 V_37 , T_3 V_38 , T_3 V_39 , T_3 V_40 ,
T_3 V_41 )
{
T_2 V_30 , V_31 ;
V_16 V_42 ;
int V_32 = 1000 ;
F_15 ( & V_42 , V_35 ,
V_36 , V_37 , V_38 ,
V_39 , V_40 , V_41 ) ;
V_30 = V_42 ;
V_31 = 0 ;
return F_12 ( V_1 -> V_6 , V_43 , & V_30 , & V_31 , V_32 ) ;
}
int F_16 ( struct V_1 * V_1 , T_4 V_44 , T_2 V_45 )
{
T_2 V_30 = ( T_2 ) V_44 , V_31 = V_45 ;
int V_32 = 1000 ;
return F_12 ( V_1 -> V_6 , V_46 , & V_30 , & V_31 , V_32 ) ;
}
int F_17 ( struct V_1 * V_1 , T_4 V_47 , T_2 V_45 )
{
T_2 V_30 = ( T_2 ) V_47 , V_31 = V_45 ;
int V_32 = 1000 ;
return F_12 ( V_1 -> V_6 , V_48 , & V_30 , & V_31 , V_32 ) ;
}
void F_18 ( struct V_1 * V_1 )
{
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_1 -> V_50 ; V_49 ++ )
F_19 ( & V_1 -> V_51 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_1 -> V_52 ; V_49 ++ )
F_20 ( & V_1 -> V_53 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_1 -> V_54 ; V_49 ++ )
F_21 ( & V_1 -> V_55 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_1 -> V_56 ; V_49 ++ )
F_22 ( & V_1 -> V_57 [ V_49 ] ) ;
}
void F_23 ( struct V_1 * V_1 )
{
V_1 -> V_50 = F_24 ( V_1 -> V_6 , V_58 ) ;
V_1 -> V_52 = F_24 ( V_1 -> V_6 , V_59 ) ;
V_1 -> V_54 = F_24 ( V_1 -> V_6 , V_60 ) ;
V_1 -> V_56 = F_24 ( V_1 -> V_6 ,
V_61 ) ;
F_9 ( F_4 ( V_1 ) ,
L_7 ,
V_1 -> V_50 , V_1 -> V_52 ,
V_1 -> V_54 , V_1 -> V_56 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
enum V_62 V_13 ;
unsigned int V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_49 ;
V_13 = F_26 ( V_1 -> V_6 ) ;
switch ( V_13 ) {
case V_68 :
case V_69 :
V_65 = 1 ;
V_66 = V_1 -> V_56 - 2 ;
break;
default:
V_65 = 0 ;
V_66 = 0 ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_52 ; V_49 ++ ) {
V_67 = V_49 ;
F_27 ( & V_1 -> V_53 [ V_49 ] ,
V_67 ,
V_65 ,
V_66 ) ;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_50 ; V_49 ++ ) {
V_67 = V_1 -> V_52 + V_49 ;
F_28 ( & V_1 -> V_51 [ V_49 ] ,
V_67 ,
V_65 ,
V_66 ) ;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_54 ; V_49 ++ ) {
switch ( V_13 ) {
case V_69 :
V_64 = V_49 ;
break;
default:
V_64 = 0 ;
break;
}
F_29 ( & V_1 -> V_55 [ V_49 ] ,
0 ,
1 ,
0 ,
0 ,
1 ,
1 ,
1 ,
0 ,
V_64 ,
0 ) ;
}
switch ( V_13 ) {
case V_70 :
case V_69 :
V_63 = 1 ;
break;
default:
V_63 = 0 ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_56 ; V_49 ++ ) {
F_30 ( & V_1 -> V_57 [ V_49 ] ,
F_31 ( V_1 -> V_4 . V_14 ) ,
V_1 -> V_4 . V_12 ,
V_63 ) ;
}
}
int F_32 ( struct V_1 * V_1 )
{
enum V_62 V_13 ;
unsigned int V_49 ;
int V_5 ;
V_13 = F_26 ( V_1 -> V_6 ) ;
F_9 ( F_4 ( V_1 ) , L_8
L_9 ,
V_1 -> V_50 , V_1 -> V_52 ,
V_1 -> V_54 , V_1 -> V_56 ,
V_13 == V_68 ? L_10 :
V_13 == V_70 ? L_11 :
V_13 == V_69 ? L_12 :
L_13 ) ;
for ( V_49 = 0 ; V_49 < V_1 -> V_50 ; V_49 ++ ) {
V_5 = F_33 ( V_1 -> V_6 , & V_1 -> V_51 [ V_49 ] , V_49 ,
V_1 -> V_4 . V_9 ,
sizeof( struct V_71 ) ) ;
if ( V_5 )
goto V_72;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_52 ; V_49 ++ ) {
V_5 = F_34 ( V_1 -> V_6 , & V_1 -> V_53 [ V_49 ] , V_49 ,
V_1 -> V_4 . V_10 ,
sizeof( struct V_73 ) ) ;
if ( V_5 )
goto V_72;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_54 ; V_49 ++ ) {
if ( V_49 < V_1 -> V_52 )
V_5 = F_35 ( V_1 -> V_6 , & V_1 -> V_55 [ V_49 ] , V_49 ,
V_1 -> V_4 . V_10 ,
sizeof( struct V_74 ) ) ;
else
V_5 = F_35 ( V_1 -> V_6 , & V_1 -> V_55 [ V_49 ] , V_49 ,
V_1 -> V_4 . V_9 ,
sizeof( struct V_75 ) ) ;
if ( V_5 )
goto V_72;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_56 ; V_49 ++ ) {
V_5 = F_36 ( V_1 -> V_6 , & V_1 -> V_57 [ V_49 ] , V_49 ) ;
if ( V_5 )
goto V_72;
}
V_1 -> V_76 = F_37 ( V_1 -> V_6 ,
V_77 , 0 ) ;
if ( ! V_1 -> V_76 && V_13 == V_68 ) {
F_3 ( F_4 ( V_1 ) ,
L_14 ) ;
V_5 = - V_78 ;
goto V_72;
}
return 0 ;
V_72:
F_18 ( V_1 ) ;
return V_5 ;
}
