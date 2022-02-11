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
F_11 ( V_27 , V_6 ) ;
V_27 -> V_41 . V_42 = F_1 ( V_2 , V_3 ) ;
F_12 ( V_27 , V_43 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
V_23 = F_13 ( V_19 ) ;
if ( ! V_23 ) {
V_35 = - V_40 ;
goto V_44;
}
if ( ! F_14 ( V_27 , V_23 , V_38 , 0 ) ) {
F_15 ( V_23 ) ;
break;
}
}
if ( V_30 == 0 )
V_35 = - V_40 ;
else
V_35 = F_16 ( V_27 ) ;
if ( V_35 )
goto V_44;
V_31 = 0 ;
V_32 = 0 ;
V_24 = 0 ;
F_17 (bv, bio, i) {
if ( ! V_29 -> V_45 )
break;
V_34 = F_18 ( V_29 -> V_45 ) ;
V_33 = 0 ;
if ( ! V_24 ) {
V_21 = (struct V_20 * ) V_34 ;
V_24 = V_21 -> V_18 ;
V_33 = sizeof( struct V_20 ) ;
}
while ( V_33 < V_29 -> V_46 &&
V_31 < V_24 && V_32 < V_22 ) {
if ( F_3 ( V_6 , V_34 + V_33 , & V_17 [ V_32 ] ) )
V_32 ++ ;
V_33 += sizeof( struct V_7 ) ;
V_31 ++ ;
}
F_19 ( V_34 ) ;
if ( V_31 >= V_24 || V_32 >= V_22 )
break;
}
* V_18 = V_32 ;
V_44:
F_17 (bv, bio, i)
F_15 ( V_29 -> V_45 ) ;
F_20 ( V_27 ) ;
return V_35 ;
}
int F_21 ( struct V_5 * V_6 ,
T_1 V_3 , T_1 V_47 ,
T_2 V_19 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_48 ;
T_1 V_49 = V_3 + V_47 ;
struct V_27 * V_27 ;
int V_35 ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_37 ;
if ( V_49 > V_6 -> V_13 -> V_14 )
return - V_50 ;
V_48 = F_2 ( V_2 ) ;
if ( V_3 & ( V_48 - 1 ) )
return - V_50 ;
if ( ( V_47 & ( V_48 - 1 ) ) &&
V_49 != V_6 -> V_13 -> V_14 )
return - V_50 ;
while ( V_3 < V_49 ) {
V_27 = F_10 ( V_19 , 0 ) ;
V_27 -> V_41 . V_42 = V_3 ;
F_11 ( V_27 , V_6 ) ;
F_12 ( V_27 , V_51 , 0 ) ;
V_35 = F_16 ( V_27 ) ;
F_20 ( V_27 ) ;
if ( V_35 )
return V_35 ;
V_3 += V_48 ;
F_22 () ;
}
return 0 ;
}
int F_23 ( struct V_5 * V_6 , T_4 V_52 ,
unsigned int V_53 , unsigned long V_54 )
{
void T_5 * V_55 = ( void T_5 * ) V_54 ;
struct V_1 * V_2 ;
struct V_56 V_8 ;
struct V_7 * V_17 ;
int V_35 ;
if ( ! V_55 )
return - V_50 ;
V_2 = F_6 ( V_6 ) ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_57 ;
if ( ! F_24 ( V_58 ) )
return - V_59 ;
if ( F_25 ( & V_8 , V_55 , sizeof( struct V_56 ) ) )
return - V_60 ;
if ( ! V_8 . V_18 )
return - V_50 ;
V_17 = F_26 ( V_8 . V_18 , sizeof( struct V_7 ) , V_61 ) ;
if ( ! V_17 )
return - V_40 ;
V_35 = F_5 ( V_6 , V_8 . V_3 ,
V_17 , & V_8 . V_18 ,
V_61 ) ;
if ( V_35 )
goto V_44;
if ( F_27 ( V_55 , & V_8 , sizeof( struct V_56 ) ) ) {
V_35 = - V_60 ;
goto V_44;
}
if ( V_8 . V_18 ) {
if ( F_27 ( V_55 + sizeof( struct V_56 ) , V_17 ,
sizeof( struct V_7 ) * V_8 . V_18 ) )
V_35 = - V_60 ;
}
V_44:
F_28 ( V_17 ) ;
return V_35 ;
}
int F_29 ( struct V_5 * V_6 , T_4 V_52 ,
unsigned int V_53 , unsigned long V_54 )
{
void T_5 * V_55 = ( void T_5 * ) V_54 ;
struct V_1 * V_2 ;
struct V_62 V_63 ;
if ( ! V_55 )
return - V_50 ;
V_2 = F_6 ( V_6 ) ;
if ( ! V_2 )
return - V_36 ;
if ( ! F_7 ( V_2 ) )
return - V_57 ;
if ( ! F_24 ( V_58 ) )
return - V_59 ;
if ( ! ( V_52 & V_64 ) )
return - V_65 ;
if ( F_25 ( & V_63 , V_55 , sizeof( struct V_62 ) ) )
return - V_60 ;
return F_21 ( V_6 , V_63 . V_3 , V_63 . V_47 ,
V_61 ) ;
}
