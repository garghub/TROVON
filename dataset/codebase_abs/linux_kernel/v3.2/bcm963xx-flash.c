static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
int V_5 = 3 , V_6 = 0 ;
struct V_7 * V_8 ;
struct V_3 * V_9 ;
int V_10 ;
T_1 V_11 ;
unsigned int V_12 , V_13 , V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 ;
int V_19 = 0 ;
int V_20 ;
char * V_21 ;
char * V_22 ;
V_8 = F_2 ( sizeof( struct V_7 ) ) ;
if ( ! V_8 )
return - V_23 ;
V_10 = V_2 -> V_24 ( V_2 , V_2 -> V_25 , sizeof( struct V_7 ) ,
& V_11 , ( void * ) V_8 ) ;
if ( V_11 != sizeof( struct V_7 ) ) {
F_3 ( V_8 ) ;
return - V_26 ;
}
sscanf ( V_8 -> V_27 , L_1 , & V_13 ) ;
sscanf ( V_8 -> V_28 , L_1 , & V_16 ) ;
sscanf ( V_8 -> V_29 , L_1 , & V_18 ) ;
V_22 = & ( V_8 -> V_30 [ 0 ] ) ;
V_21 = & ( V_8 -> V_31 [ 0 ] ) ;
F_4 (KERN_INFO PFX L_2
L_3 , tagversion, boardid) ;
V_13 = V_13 - V_32 ;
V_12 = V_13 + V_16 ;
V_14 = F_5 ( V_18 , V_2 -> V_25 ) + V_2 -> V_25 ;
V_17 = V_2 -> V_33 - V_14 - V_2 -> V_25 ;
V_15 = V_14 - V_12 ;
V_19 = 8 ;
if ( V_15 > 0 ) {
V_5 ++ ;
V_19 += 6 ;
} ;
if ( V_16 > 0 ) {
V_5 ++ ;
V_19 += 6 ;
} ;
V_9 = F_6 ( sizeof( * V_9 ) * V_5 + 10 * V_5 , V_34 ) ;
if ( ! V_9 ) {
F_3 ( V_8 ) ;
return - V_23 ;
} ;
V_9 [ V_6 ] . V_35 = L_4 ;
V_9 [ V_6 ] . V_36 = 0 ;
V_9 [ V_6 ] . V_33 = V_2 -> V_25 ;
V_6 ++ ;
if ( V_16 > 0 ) {
V_9 [ V_6 ] . V_35 = L_5 ;
V_9 [ V_6 ] . V_36 = V_13 ;
V_9 [ V_6 ] . V_33 = V_16 ;
V_6 ++ ;
} ;
if ( V_15 > 0 ) {
V_9 [ V_6 ] . V_35 = L_6 ;
V_9 [ V_6 ] . V_36 = V_12 ;
V_9 [ V_6 ] . V_33 = V_15 ;
if ( V_17 > 0 )
V_9 [ V_6 ] . V_33 += V_17 ;
V_6 ++ ;
} ;
V_9 [ V_6 ] . V_35 = L_7 ;
V_9 [ V_6 ] . V_36 = V_2 -> V_33 - V_2 -> V_25 ;
V_9 [ V_6 ] . V_33 = V_2 -> V_25 ;
V_6 ++ ;
V_9 [ V_6 ] . V_35 = L_8 ;
V_9 [ V_6 ] . V_36 = V_9 [ 0 ] . V_33 ;
V_9 [ V_6 ] . V_33 = V_2 -> V_33 - V_9 [ 0 ] . V_33 - V_9 [ 3 ] . V_33 ;
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ )
F_4 (KERN_INFO PFX L_9
L_10 , i, parts[i].name,
(long unsigned int)(parts[i].offset),
(long unsigned int)(parts[i].size)) ;
F_4 (KERN_INFO PFX L_11 ,
spareaddr, sparelen) ;
* V_4 = V_9 ;
F_3 ( V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_37 = 0x4e0 ;
static char V_38 [ 8 ] = L_12 ;
char V_8 [ 9 ] ;
int V_10 ;
T_1 V_11 ;
V_10 = V_2 -> V_24 ( V_2 , V_37 , 8 , & V_11 , ( void * ) V_8 ) ;
V_8 [ V_11 ] = 0 ;
F_4 (KERN_INFO PFX L_13 , buf) ;
return strncmp ( V_38 , V_8 , 8 ) ;
}
static int F_8 ( struct V_39 * V_40 )
{
int V_41 = 0 ;
int V_42 = 0 ;
char * V_43 ;
struct V_44 * V_45 ;
V_45 = F_9 ( V_40 , V_46 , 0 ) ;
if ( ! V_45 ) {
F_10 ( & V_40 -> V_47 , L_14 ) ;
return - V_48 ;
}
V_49 . V_50 = V_45 -> V_51 ;
V_49 . V_33 = F_11 ( V_45 ) ;
V_49 . V_52 = F_12 ( V_45 -> V_51 , F_11 ( V_45 ) ) ;
if ( ! V_49 . V_52 ) {
F_10 ( & V_40 -> V_47 , L_15 ) ;
return - V_26 ;
}
F_13 ( & V_40 -> V_47 , L_16 ,
V_49 . V_33 , V_49 . V_50 ) ;
F_14 ( & V_49 ) ;
V_53 = F_15 ( L_17 , & V_49 ) ;
if ( ! V_53 ) {
F_10 ( & V_40 -> V_47 , L_18 ) ;
V_53 = F_15 ( L_19 , & V_49 ) ;
if ( V_53 )
goto V_54;
F_10 ( & V_40 -> V_47 , L_20 ) ;
V_41 = - V_26 ;
goto V_55;
}
V_54:
V_53 -> V_56 = V_57 ;
if ( F_7 ( V_53 ) == 0 ) {
F_13 ( & V_40 -> V_47 , L_21 ) ;
if ( V_42 == 0 ) {
int V_10 = F_1 ( V_53 ,
& V_58 ) ;
if ( V_10 > 0 ) {
V_43 = L_4 ;
V_42 = V_10 ;
}
}
} else {
F_13 ( & V_40 -> V_47 , L_22 ) ;
V_41 = - V_48 ;
goto V_55;
}
return F_16 ( V_53 , V_58 ,
V_42 ) ;
V_55:
F_17 ( V_49 . V_52 ) ;
return V_41 ;
}
static int F_18 ( struct V_39 * V_40 )
{
if ( V_53 ) {
F_19 ( V_53 ) ;
F_20 ( V_53 ) ;
}
if ( V_49 . V_52 ) {
F_17 ( V_49 . V_52 ) ;
V_49 . V_52 = 0 ;
}
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_59 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_59 ) ;
}
