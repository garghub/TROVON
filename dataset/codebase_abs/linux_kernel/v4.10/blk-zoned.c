static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 ) - 1 ;
return V_3 & ~ V_4 ;
}
static bool F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_7 * V_9 )
{
T_1 V_10 = F_4 ( V_6 ) ;
if ( V_8 -> V_11 < V_10 )
return false ;
V_8 -> V_11 -= V_10 ;
if ( V_8 -> V_11 + V_8 -> V_12 > V_6 -> V_13 -> V_14 )
return false ;
if ( V_8 -> type == V_15 )
V_8 -> V_16 = V_8 -> V_11 + V_8 -> V_12 ;
else
V_8 -> V_16 -= V_10 ;
memcpy ( V_9 , V_8 , sizeof( struct V_7 ) ) ;
return true ;
}
int F_5 ( struct V_5 * V_6 ,
T_1 V_3 ,
struct V_7 * V_17 ,
unsigned int * V_18 ,
T_2 V_19 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_20 * V_21 ;
unsigned int V_22 = * V_18 ;
struct V_23 * V_23 ;
unsigned int V_24 ;
T_3 V_25 ;
unsigned int V_26 ;
struct V_27 * V_27 ;
struct V_28 * V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 ;
void * V_34 ;
int V_35 ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
if ( ! V_22 )
return 0 ;
if ( V_3 > V_6 -> V_13 -> V_14 ) {
* V_18 = 0 ;
return 0 ;
}
V_25 = sizeof( struct V_20 ) +
sizeof( struct V_7 ) * V_22 ;
V_25 = ( V_25 + V_38 - 1 ) & V_39 ;
if ( V_25 > ( F_8 ( V_2 ) << 9 ) )
V_25 = F_8 ( V_2 ) << 9 ;
V_26 = F_9 (unsigned int, BIO_MAX_PAGES,
rep_bytes >> PAGE_SHIFT) ;
V_26 = F_9 (unsigned int, nr_pages,
queue_max_segments(q)) ;
V_27 = F_10 ( V_19 , V_26 ) ;
if ( ! V_27 )
return - V_40 ;
V_27 -> V_41 = V_6 ;
V_27 -> V_42 . V_43 = F_1 ( V_2 , V_3 ) ;
F_11 ( V_27 , V_44 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
V_23 = F_12 ( V_19 ) ;
if ( ! V_23 ) {
V_35 = - V_40 ;
goto V_45;
}
if ( ! F_13 ( V_27 , V_23 , V_38 , 0 ) ) {
F_14 ( V_23 ) ;
break;
}
}
if ( V_30 == 0 )
V_35 = - V_40 ;
else
V_35 = F_15 ( V_27 ) ;
if ( V_35 )
goto V_45;
V_31 = 0 ;
V_32 = 0 ;
V_24 = 0 ;
F_16 (bv, bio, i) {
if ( ! V_29 -> V_46 )
break;
V_34 = F_17 ( V_29 -> V_46 ) ;
V_33 = 0 ;
if ( ! V_24 ) {
V_21 = (struct V_20 * ) V_34 ;
V_24 = V_21 -> V_18 ;
V_33 = sizeof( struct V_20 ) ;
}
while ( V_33 < V_29 -> V_47 &&
V_31 < V_24 && V_32 < V_22 ) {
if ( F_3 ( V_6 , V_34 + V_33 , & V_17 [ V_32 ] ) )
V_32 ++ ;
V_33 += sizeof( struct V_7 ) ;
V_31 ++ ;
}
F_18 ( V_34 ) ;
if ( V_31 >= V_24 || V_32 >= V_22 )
break;
}
* V_18 = V_32 ;
V_45:
F_16 (bv, bio, i)
F_14 ( V_29 -> V_46 ) ;
F_19 ( V_27 ) ;
return V_35 ;
}
int F_20 ( struct V_5 * V_6 ,
T_1 V_3 , T_1 V_48 ,
T_2 V_19 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_49 ;
T_1 V_50 = V_3 + V_48 ;
struct V_27 * V_27 ;
int V_35 ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
if ( V_50 > V_6 -> V_13 -> V_14 )
return - V_51 ;
V_49 = F_2 ( V_2 ) ;
if ( V_3 & ( V_49 - 1 ) )
return - V_51 ;
if ( ( V_48 & ( V_49 - 1 ) ) &&
V_50 != V_6 -> V_13 -> V_14 )
return - V_51 ;
while ( V_3 < V_50 ) {
V_27 = F_10 ( V_19 , 0 ) ;
V_27 -> V_42 . V_43 = V_3 ;
V_27 -> V_41 = V_6 ;
F_11 ( V_27 , V_52 , 0 ) ;
V_35 = F_15 ( V_27 ) ;
F_19 ( V_27 ) ;
if ( V_35 )
return V_35 ;
V_3 += V_49 ;
F_21 () ;
}
return 0 ;
}
int F_22 ( struct V_5 * V_6 , T_4 V_53 ,
unsigned int V_54 , unsigned long V_55 )
{
void T_5 * V_56 = ( void T_5 * ) V_55 ;
struct V_1 * V_2 ;
struct V_57 V_8 ;
struct V_7 * V_17 ;
int V_35 ;
if ( ! V_56 )
return - V_51 ;
V_2 = F_6 ( V_6 ) ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_58 ;
if ( ! F_23 ( V_59 ) )
return - V_60 ;
if ( F_24 ( & V_8 , V_56 , sizeof( struct V_57 ) ) )
return - V_61 ;
if ( ! V_8 . V_18 )
return - V_51 ;
V_17 = F_25 ( V_8 . V_18 , sizeof( struct V_7 ) , V_62 ) ;
if ( ! V_17 )
return - V_40 ;
V_35 = F_5 ( V_6 , V_8 . V_3 ,
V_17 , & V_8 . V_18 ,
V_62 ) ;
if ( V_35 )
goto V_45;
if ( F_26 ( V_56 , & V_8 , sizeof( struct V_57 ) ) ) {
V_35 = - V_61 ;
goto V_45;
}
if ( V_8 . V_18 ) {
if ( F_26 ( V_56 + sizeof( struct V_57 ) , V_17 ,
sizeof( struct V_7 ) * V_8 . V_18 ) )
V_35 = - V_61 ;
}
V_45:
F_27 ( V_17 ) ;
return V_35 ;
}
int F_28 ( struct V_5 * V_6 , T_4 V_53 ,
unsigned int V_54 , unsigned long V_55 )
{
void T_5 * V_56 = ( void T_5 * ) V_55 ;
struct V_1 * V_2 ;
struct V_63 V_64 ;
if ( ! V_56 )
return - V_51 ;
V_2 = F_6 ( V_6 ) ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_58 ;
if ( ! F_23 ( V_59 ) )
return - V_60 ;
if ( ! ( V_53 & V_65 ) )
return - V_66 ;
if ( F_24 ( & V_64 , V_56 , sizeof( struct V_63 ) ) )
return - V_61 ;
return F_20 ( V_6 , V_64 . V_3 , V_64 . V_48 ,
V_62 ) ;
}
